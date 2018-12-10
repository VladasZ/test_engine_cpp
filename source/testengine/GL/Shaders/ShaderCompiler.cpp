
#include <cstdio>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

#include "GL.hpp"
#include "Debug.hpp"
#include "ShaderCompiler.hpp"

using namespace std;

std::string ShaderCompiler::shader_version() {
#if IOS
    return "#version 300 core";
#else
    return "#version 330 core";
#endif
}

int ShaderCompiler::compile(const string& vertex_path, const string& fragment_path)
{
	GLuint vertex_shader_id   = GL(glCreateShader(GL_VERTEX_SHADER));
	GLuint fragment_shader_id = GL(glCreateShader(GL_FRAGMENT_SHADER));

    string vertex_shader_code = shader_version();
	ifstream vertex_shader_stream(vertex_path.c_str(), ios::in);
    
#if SHADER_COMPILER_OUTPUT
    
    Log(vertexPath);
    Log(fragmentPath);
    
#endif
    
	if (vertex_shader_stream.is_open())  {
		string line = "";
		while(getline(vertex_shader_stream, line))
			vertex_shader_code += "\n" + line;
		vertex_shader_stream.close();
	}
    else {
        Error("Impossible to open " << vertex_path.c_str());
		getchar();
		return 0;
	}

	string fragment_shader_code = shader_version();
	ifstream fragment_shader_stream(fragment_path.c_str(), ios::in);
    
	if (fragment_shader_stream.is_open()) {
		string line = "";
		while(getline(fragment_shader_stream, line))
			fragment_shader_code += "\n" + line;
		fragment_shader_stream.close();
	}

	GLint result = GL_FALSE;
	int info_log_length;
    
#if SHADER_COMPILER_OUTPUT
    Log("Compiling shader :" << vertexPath.c_str());
#endif
    
	char const* vertex_source_pointer = vertex_shader_code.c_str();
	GL(glShaderSource(vertex_shader_id, 1, &vertex_source_pointer , NULL));
	GL(glCompileShader(vertex_shader_id));

	GL(glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &result));
	GL(glGetShaderiv(vertex_shader_id, GL_INFO_LOG_LENGTH, &info_log_length));
    
	if (info_log_length > 0) {
		vector<char> vertex_shader_error_message(info_log_length + 1);
		GL(glGetShaderInfoLog(vertex_shader_id, info_log_length, NULL, &vertex_shader_error_message[0]));
		Error(&vertex_shader_error_message[0]);
	}

#if SHADER_COMPILER_OUTPUT
    Log("Compiling shader :" << fragmentPath.c_str());
#endif

	char const* fragment_source_pointer = fragment_shader_code.c_str();
	GL(glShaderSource(fragment_shader_id, 1, &fragment_source_pointer , NULL));
	GL(glCompileShader(fragment_shader_id));

	GL(glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &result));
	GL(glGetShaderiv(fragment_shader_id, GL_INFO_LOG_LENGTH, &info_log_length));
    
	if (info_log_length > 0) {
		vector<char> fragment_shader_error_message(info_log_length + 1);
		GL(glGetShaderInfoLog(fragment_shader_id, info_log_length, NULL, &fragment_shader_error_message[0]));
        Error(&fragment_shader_error_message[0]);
	}

#if SHADER_COMPILER_OUTPUT
    Log("Linking program");
#endif

	GLuint program_id = glCreateProgram();
	GL(glAttachShader(program_id, vertex_shader_id));
	GL(glAttachShader(program_id, fragment_shader_id));
	GL(glLinkProgram(program_id));

	GL(glGetProgramiv(program_id, GL_LINK_STATUS, &result));
	GL(glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length));
    
	if (info_log_length > 0) {
		vector<char> program_error_message(info_log_length + 1);
		GL(glGetProgramInfoLog(program_id, info_log_length, NULL, &program_error_message[0]));
        Error(&program_error_message[0]);
	}
	
	GL(glDetachShader(program_id, vertex_shader_id));
	GL(glDetachShader(program_id, fragment_shader_id));
	
	GL(glDeleteShader(vertex_shader_id));
	GL(glDeleteShader(fragment_shader_id));

	return program_id;
}
