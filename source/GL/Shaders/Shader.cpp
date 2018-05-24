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
Shader Shader::sprite;

Shader::Shader(const String &vertexPath, const String &fragmentPath) {    
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

    sprite =        Shader(FileManager::assetsDirectory() + "Shaders/sprite.vert",
                           FileManager::assetsDirectory() + "Shaders/sprite.frag");
    
    setupUiTranslation();
}

void Shader::setupUiTranslation() {
    
    mat4 uiProjection = scale(mat4(), vec3(2 / Window::size.width, -(2 / Window::size.height), 1));
    uiProjection = translate(uiProjection, vec3(-Window::size.width / 2, - Window::size.height / 2, 0));
    
    Shader::ui.use();
    Shader::ui.setUITranslationMatrix(uiProjection);
    
    Shader::uiTexture.use();
    Shader::uiTexture.setUITranslationMatrix(uiProjection);
    
    Shader::uiMonochrome.use();
    Shader::uiMonochrome.setUITranslationMatrix(uiProjection);
    
    Shader::sprite.use();
    Shader::sprite.setUITranslationMatrix(uiProjection);
}

void Shader::setUniformColor(const Color &color) {
    if (uniformColor == -1)
        uniformColor = glGetUniformLocation(program, "uniformColor");
    color.setToUniform(uniformColor);
}

void Shader::setUITranslationMatrix(const mat4 &projection) {
    if (uiTranslation == -1)
        uiTranslation = glGetUniformLocation(program, "uiTranslation");
    GL(glUniformMatrix4fv(uiTranslation, 1, false, &projection[0][0]));
}

void Shader::setTransformMatrix(const mat4 &transform) {
    if (this->transform == -1)
        this->transform = glGetUniformLocation(program, "transform");
    GL(glUniformMatrix4fv(this->transform, 1, false, &transform[0][0]));
}

void Shader::setUniformPosition(float x, float y) {
    if (uniformPosition == -1)
        uniformPosition = glGetUniformLocation(program, "uniformPosition");
    glUniform2f(uniformPosition, x, y);

}

