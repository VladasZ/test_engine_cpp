//
//  Shader.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Shader.hpp"
#include "ShaderCompiler.hpp"
#include "GL.hpp"
#include "Window.hpp"
#include "FileManager.hpp"
#include "Debug.hpp"


Shader Shader::ui;
Shader Shader::uiTexture;
Shader Shader::uiMonochrome;
Shader Shader::uiPath;
Shader Shader::sprite;
Shader Shader::simple3D;

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath) {    
    program = ShaderCompiler::compile(vertexPath, fragmentPath);
}

void Shader::use() const {
    GL(glUseProgram(program));
}

void Shader::initialize() {

    ui =            Shader(FileManager::assetsDirectory() + "Shaders/ui.vert",
                           FileManager::assetsDirectory() + "Shaders/ui.frag");
    
    uiTexture =     Shader(FileManager::assetsDirectory() + "Shaders/uiTexture.vert",
                           FileManager::assetsDirectory() + "Shaders/uiTexture.frag");
    
    uiMonochrome =  Shader(FileManager::assetsDirectory() + "Shaders/uiMonochrome.vert",
                           FileManager::assetsDirectory() + "Shaders/uiMonochrome.frag");

    uiPath =        Shader(FileManager::assetsDirectory() + "Shaders/uiPath.vert",
                           FileManager::assetsDirectory() + "Shaders/uiPath.frag");

    sprite =        Shader(FileManager::assetsDirectory() + "Shaders/sprite.vert",
                           FileManager::assetsDirectory() + "Shaders/sprite.frag");
    
    simple3D =      Shader(FileManager::assetsDirectory() + "Shaders/simple3D.vert",
                           FileManager::assetsDirectory() + "Shaders/simple3D.frag");
}

void Shader::setUniformColor(const Color &color) {
    if (uniformColor == -1)
        uniformColor = glGetUniformLocation(program, "uniformColor");
	GL(glUniform4fv(uniformColor, 1, &color.r));
}

void Shader::setUITranslationMatrix(const mat4 &projection) {
    if (viewportTranslation == -1)
        viewportTranslation = glGetUniformLocation(program, "uiTranslation");
   // GL(glUniformMatrix4fv(viewportTranslation, 1, false, &projection[0][0]));
}

void Shader::setTransformMatrix(const mat4 &transform) {
    if (this->transform == -1)
        this->transform = glGetUniformLocation(program, "transform");
   // GL(glUniformMatrix4fv(this->transform, 1, false, &transform[0][0]));
}

void Shader::setUniformPosition(float x, float y) {
    if (uniformPosition == -1)
        uniformPosition = glGetUniformLocation(program, "uniformPosition");
    glUniform2f(uniformPosition, x, y);
}

void Shader::setViewportTranslation(const Size &viewport) {/*
    mat4 viewportTranslation = scale(mat4(), vec3(2 / viewport.width, -(2 / viewport.height), 1));
    viewportTranslation = translate(viewportTranslation, vec3(-viewport.width / 2, -viewport.height / 2, 0));
    use();
    setUITranslationMatrix(viewportTranslation);*/
}
