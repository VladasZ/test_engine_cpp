#pragma once

#include "GL.hpp"

GLuint compileShaders();
GLuint compileShaders(const string &vertex_file_path, const string &fragment_file_path);
