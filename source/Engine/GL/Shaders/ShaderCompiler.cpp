
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

#include "Array.hpp"
#include "ShaderCompiler.hpp"
#include "GL.hpp"
#include "Debug.hpp"

using namespace std;

std::string ShaderCompiler::shaderVersion() {
    
#if WINDOWS || MAC_OS
    return "#version 330 core";
#elif IOS
    return "#version 300 core";
#else
    NOT_IMPLEMENTED;
    return "";
#endif
}

int ShaderCompiler::compile(const std::string &vertexPath, const std::string &fragmentPath)
{
	GLuint VertexShaderID = GL(glCreateShader(GL_VERTEX_SHADER));
	GLuint FragmentShaderID = GL(glCreateShader(GL_FRAGMENT_SHADER));

    std::string VertexShaderCode = shaderVersion();
	ifstream VertexShaderStream(vertexPath.c_str(), ios::in);
    
#if SHADER_COMPILER_OUTPUT
    
    Log(vertexPath);
    Log(fragmentPath);
    
#endif
    
	if (VertexShaderStream.is_open())
    {
		string Line = "";
        
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
        
		VertexShaderStream.close();
	}
    else
    {
        Error("Impossible to open " << vertexPath.c_str());
		getchar();
		return 0;
	}

	string FragmentShaderCode = shaderVersion();
	ifstream FragmentShaderStream(fragmentPath.c_str(), ios::in);
    
	if (FragmentShaderStream.is_open())
    {
		string Line = "";
        
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
        
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;
    
#if SHADER_COMPILER_OUTPUT
    Log("Compiling shader :" << vertexPath.c_str());
#endif
    
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	GL(glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL));
	GL(glCompileShader(VertexShaderID));

	GL(glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result));
	GL(glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength));
    
	if ( InfoLogLength > 0 )
    {
		Array<char> VertexShaderErrorMessage(InfoLogLength + 1);
		GL(glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]));
		Error(&VertexShaderErrorMessage[0]);
	}

#if SHADER_COMPILER_OUTPUT
    Log("Compiling shader :" << fragmentPath.c_str());
#endif

	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	GL(glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL));
	GL(glCompileShader(FragmentShaderID));

	GL(glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result));
	GL(glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength));
    
	if ( InfoLogLength > 0 )
    {
		Array<char> FragmentShaderErrorMessage(InfoLogLength+1);
		GL(glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]));
        Error(&FragmentShaderErrorMessage[0]);
	}
#if SHADER_COMPILER_OUTPUT
    Log("Linking program");
#endif
	GLuint ProgramID = glCreateProgram();
	GL(glAttachShader(ProgramID, VertexShaderID));
	GL(glAttachShader(ProgramID, FragmentShaderID));
	GL(glLinkProgram(ProgramID));

	GL(glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result));
	GL(glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength));
    
	if (InfoLogLength > 0)
    {
		Array<char> ProgramErrorMessage(InfoLogLength+1);
		GL(glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]));
        Error(&ProgramErrorMessage[0]);
	}
	
	GL(glDetachShader(ProgramID, VertexShaderID));
	GL(glDetachShader(ProgramID, FragmentShaderID));
	
	GL(glDeleteShader(VertexShaderID));
	GL(glDeleteShader(FragmentShaderID));

	return ProgramID;
}
