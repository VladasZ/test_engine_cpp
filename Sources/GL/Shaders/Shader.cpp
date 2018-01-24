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


Shader Shader::simple;
Shader Shader::ui;
Shader Shader::colorVertices;
Shader Shader::texture;
Shader Shader::uiTexture;
Shader Shader::uiMonochrome;

Shader::Shader(const string &vertexPath, const string &fragmentPath) {
    
    program = ShaderCompiler::compile(vertexPath, fragmentPath);
    
    uniformColor = glGetUniformLocation(program, "uniformColor");
    uniformProjection = glGetUniformLocation(program, "uniformProjection");
}

void Shader::use() const {
    glUseProgram(program);
}

void Shader::initialize() {
    
    simple = Shader(FileManager::assetsDirectory() + "Shaders/simple.vert",
                    FileManager::assetsDirectory() + "Shaders/simple.frag");
    
    ui = Shader(FileManager::assetsDirectory() + "Shaders/ui.vert",
                FileManager::assetsDirectory() + "Shaders/ui.frag");
    
    uiTexture = Shader(FileManager::assetsDirectory() + "Shaders/uiTexture.vert",
                       FileManager::assetsDirectory() + "Shaders/uiTexture.frag");
    
    uiMonochrome = Shader(FileManager::assetsDirectory() + "Shaders/uiMonochrome.vert",
                          FileManager::assetsDirectory() + "Shaders/uiMonochrome.frag");
    
    colorVertices = Shader(FileManager::assetsDirectory() + "Shaders/colorVertices.vert",
                           FileManager::assetsDirectory() + "Shaders/colorVertices.frag");
    
    texture = Shader(FileManager::assetsDirectory() + "Shaders/texture.vert",
                     FileManager::assetsDirectory() + "Shaders/texture.frag");
    
    setupUiTranslation();
}

void Shader::setupUiTranslation() {
    
    mat4 uiProjection = scale(mat4(), vec3(2 / Window::size.width, -(2 / Window::size.height), 1));
    uiProjection = translate(uiProjection, vec3(-Window::size.width / 2, - Window::size.height / 2, 0));
    
    Shader::ui.use();
    Shader::ui.setUniformProjectionMatrix(uiProjection);
    
    Shader::uiTexture.use();
    Shader::uiTexture.setUniformProjectionMatrix(uiProjection);
    
    Shader::uiMonochrome.use();
    Shader::uiMonochrome.setUniformProjectionMatrix(uiProjection);
}

void Shader::setUniformColor(const Color &color) const {
    
    color.setToUniform(uniformColor);
}

void Shader::setUniformProjectionMatrix(const mat4 &projection) const {
    
    glUniformMatrix4fv(uniformProjection, 1, false, &projection[0][0]);
}

