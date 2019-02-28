//
//  Shader.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include             "GL.hpp"
#include            "Log.hpp"
#include          "Paths.hpp"
#include          "Debug.hpp"
#include         "Screen.hpp"
#include         "Shader.hpp"
#include "ShaderCompiler.hpp"


Shader* Shader::ui           ;
Shader* Shader::ui_texture   ;
Shader* Shader::ui_monochrome;

Shader* Shader::  simple3D;
Shader* Shader:: colored3D;
Shader* Shader::textured3D;

Shader* Shader::diffuse_colored;



Shader::Shader(const std::string& name) : name(name) {
    _program = ShaderCompiler::compile(Paths::shaders_directory() + name + ".vert",
                                       Paths::shaders_directory() + name + ".frag");

    _uniform_color  = glGetUniformLocation(_program, "uniform_color" );
    _mvp_matrix     = glGetUniformLocation(_program, "mvp_matrix"    );
    _model_matrix   = glGetUniformLocation(_program, "model_matrix"  );
    _light_position = glGetUniformLocation(_program, "light_position");
}

void Shader::use() const {
    GL(glUseProgram(_program));
}

unsigned int Shader::get_program_id() const {
    return _program;
}

void Shader::initialize() {
    ui              = new Shader("ui");
    ui_texture      = new Shader("ui_texture");
    ui_monochrome   = new Shader("ui_monochrome");
    simple3D        = new Shader("simple3D");
    colored3D       = new Shader("colored3D");
    textured3D      = new Shader("textured3D");
    diffuse_colored = new Shader("diffuse_colored");
}

void Shader::set_uniform_color(const Color& color) {
    if (_uniform_color != -1)
        GL(glUniform4fv(_uniform_color, 1, &color.r));
}

void Shader::set_mvp_matrix(const Matrix4& mvp) {
    if (_mvp_matrix != -1)
        GL(glUniformMatrix4fv(_mvp_matrix, 1, false, &mvp.data[0][0]));
}

void Shader::set_model_matrix(const Matrix4& model_matrix) {
    if (_model_matrix != -1)
        GL(glUniformMatrix4fv(_model_matrix, 1, false, &model_matrix.data[0][0]));
}

void Shader::set_light_position(const Vector3& light_position) {
    if (_light_position != -1)
        GL(glUniform3fv(_light_position, 1, &light_position.x));
}
