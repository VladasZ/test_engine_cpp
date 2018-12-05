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
Shader Shader::uiTexture;
Shader Shader::uiMonochrome;
Shader Shader::uiPath;
Shader Shader::sprite;
Shader Shader::simple3D;
Shader Shader::colored3D;


Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath) {    
    program = ShaderCompiler::compile(vertexPath, fragmentPath);
}

void Shader::use() const {
    GL(glUseProgram(program));
}

void Shader::initialize() {

    ui =            Shader(Paths::assetsDirectory() + "Shaders/ui.vert",
                           Paths::assetsDirectory() + "Shaders/ui.frag");
    
    uiTexture =     Shader(Paths::assetsDirectory() + "Shaders/uiTexture.vert",
                           Paths::assetsDirectory() + "Shaders/uiTexture.frag");
    
    uiMonochrome =  Shader(Paths::assetsDirectory() + "Shaders/uiMonochrome.vert",
                           Paths::assetsDirectory() + "Shaders/uiMonochrome.frag");

    uiPath =        Shader(Paths::assetsDirectory() + "Shaders/uiPath.vert",
                           Paths::assetsDirectory() + "Shaders/uiPath.frag");

    sprite =        Shader(Paths::assetsDirectory() + "Shaders/sprite.vert",
                           Paths::assetsDirectory() + "Shaders/sprite.frag");
    
    simple3D =      Shader(Paths::assetsDirectory() + "Shaders/simple3D.vert",
                           Paths::assetsDirectory() + "Shaders/simple3D.frag");
    
    colored3D =     Shader(Paths::assetsDirectory() + "Shaders/colored3D.vert",
                           Paths::assetsDirectory() + "Shaders/colored3D.frag");
}

void Shader::setUniformColor(const ui::Color& color) {
    if (uniformColor == -1)
        uniformColor = glGetUniformLocation(program, "uniformColor");
	GL(glUniform4fv(uniformColor, 1, &color.r));
}

void Shader::setMVPMatrix(const Matrix4& mvp) {
	if (mvpMatrix == -1)
		mvpMatrix = glGetUniformLocation(program, "mvpMatrix");
	GL(glUniformMatrix4fv(mvpMatrix, 1, false, &mvp.data[0][0]));
}

void Shader::setUniformPosition(float x, float y) {
    if (uniformPosition == -1)
        uniformPosition = glGetUniformLocation(program, "uniformPosition");
    glUniform2f(uniformPosition, x, y);
}

