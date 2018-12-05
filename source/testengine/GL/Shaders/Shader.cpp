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
#include "Window.hpp"
#include "Shader.hpp"
#include "ShaderCompiler.hpp"


Shader Shader::ui;
Shader Shader::ui_texture;
Shader Shader::ui_monochrome;
Shader Shader::ui_path;
Shader Shader::sprite;
Shader Shader::simple3D;
Shader Shader::colored3D;


Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {    
    _program = ShaderCompiler::compile(vertexPath, fragmentPath);
}

void Shader::use() const {
    GL(glUseProgram(_program));
}

void Shader::initialize() {

    ui =            Shader(Paths::assetsDirectory() + "Shaders/ui.vert",
                           Paths::assetsDirectory() + "Shaders/ui.frag");
    
    ui_texture =    Shader(Paths::assetsDirectory() + "Shaders/uiTexture.vert",
                           Paths::assetsDirectory() + "Shaders/uiTexture.frag");
    
    ui_monochrome = Shader(Paths::assetsDirectory() + "Shaders/uiMonochrome.vert",
                           Paths::assetsDirectory() + "Shaders/uiMonochrome.frag");

    ui_path =       Shader(Paths::assetsDirectory() + "Shaders/uiPath.vert",
                           Paths::assetsDirectory() + "Shaders/uiPath.frag");

    sprite =        Shader(Paths::assetsDirectory() + "Shaders/sprite.vert",
                           Paths::assetsDirectory() + "Shaders/sprite.frag");
    
    simple3D =      Shader(Paths::assetsDirectory() + "Shaders/simple3D.vert",
                           Paths::assetsDirectory() + "Shaders/simple3D.frag");
    
    colored3D =     Shader(Paths::assetsDirectory() + "Shaders/colored3D.vert",
                           Paths::assetsDirectory() + "Shaders/colored3D.frag");
}

void Shader::set_uniform_color(const ui::Color& color) {
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

