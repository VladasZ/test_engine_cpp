#include <stdio.h>
#include <fstream>
#include <algorithm>

#include <stdlib.h>
#include <string.h>

#include "ShaderManager.hpp"

#include "GL.hpp"
#include "STL.hpp"
#include "FileManager.hpp"
#include "Platform.h"
#include "Debug.hpp"

string ShaderManager::shaderVersion() {
    
#if WINDOWS || MAC_OS
    return "#version 330 core";
#elif IOS
    return "#version 300 core";
#else
    NOT_IMPLEMENTED;
    return "";
#endif
}

GLuint ShaderManager::compileShaders() {
        
    return compileShaders(FileManager::assetsDirectory() + "Shaders/vert.vert",
                          FileManager::assetsDirectory() + "Shaders/frag.frag");
}

GLuint ShaderManager::compileShaders(const string &vertexPath, const string &fragmentPath)
{
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	string VertexShaderCode = shaderVersion();
	ifstream VertexShaderStream(vertexPath.c_str(), std::ios::in);
    
	if (VertexShaderStream.is_open())
    {
		string Line = "";
        
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
        
		VertexShaderStream.close();
	}
    else
    {
		printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertexPath.c_str());
		getchar();
		return 0;
	}

	string FragmentShaderCode = shaderVersion();
	ifstream FragmentShaderStream(fragmentPath.c_str(), std::ios::in);
    
	if (FragmentShaderStream.is_open())
    {
		string Line = "";
        
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
        
		FragmentShaderStream.close();
	}

	GLint Result = GL_FALSE;
	int InfoLogLength;

	printf("Compiling shader : %s\n", vertexPath.c_str());
	char const * VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
	glCompileShader(VertexShaderID);

	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    
	if ( InfoLogLength > 0 )
    {
		vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		printf("%s\n", &VertexShaderErrorMessage[0]);
	}

	printf("Compiling shader : %s\n", fragmentPath.c_str());
	char const * FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
	glCompileShader(FragmentShaderID);

	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    
	if ( InfoLogLength > 0 )
    {
		std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
		printf("%s\n", &FragmentShaderErrorMessage[0]);
	}

	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);

	glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    
	if (InfoLogLength > 0)
    {
		vector<char> ProgramErrorMessage(InfoLogLength+1);
		glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}
	
	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);

	return ProgramID;
}


