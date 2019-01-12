//
//  Shader.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "GL.hpp"
#include "Paths.hpp"
#include "Debug.hpp"
#include "Screen.hpp"
#include "Shader.hpp"
#include "ShaderCompiler.hpp"


Shader Shader::ui;
Shader Shader::ui_texture;
Shader Shader::ui_monochrome;
Shader Shader::ui_path;
Shader Shader::sprite;
Shader Shader::simple3D;
Shader Shader::colored3D;


Shader::Shader(const std::string& name) {
    _program = ShaderCompiler::compile(Paths::shaders_directory() + name + ".vert",
                                       Paths::shaders_directory() + name + ".frag");
}

void Shader::use() const {
    GL(glUseProgram(_program));
}

void Shader::initialize() {
    ui            = Shader("ui");
    ui_texture    = Shader("ui_texture");
    ui_monochrome = Shader("ui_monochrome");
    ui_path       = Shader("ui_path");
    sprite        = Shader("sprite");
    simple3D      = Shader("simple3D");
    colored3D     = Shader("colored3D");
}

void Shader::set_uniform_color(const Color& color) {
    if (_uniform_color == -1)
        _uniform_color = glGetUniformLocation(_program, "uniformColor");
	GL(glUniform4fv(_uniform_color, 1, &color.r));
}

void Shader::set_mvp_matrix(const Matrix4& mvp) {
	if (_mvp_matrix == -1)
		_mvp_matrix = glGetUniformLocation(_program, "mvpMatrix");
	GL(glUniformMatrix4fv(_mvp_matrix, 1, false, &mvp.data[0][0]));
}

void Shader::set_uniform_position(float x, float y) {
    if (_uniform_position == -1)
        _uniform_position = glGetUniformLocation(_program, "uniformPosition");
    glUniform2f(_uniform_position, x, y);
}
