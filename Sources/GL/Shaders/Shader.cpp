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
Shader Shader::sprite;

Shader::Shader(const String &vertexPath, const String &fragmentPath) {    
    program = ShaderCompiler::compile(vertexPath, fragmentPath);
}

void Shader::use() const {
    GL(glUseProgram(program));
}

void Shader::initialize() {
    
    simple =        Shader(FileManager::assetsDirectory() + "Shaders/simple.vert",
                           FileManager::assetsDirectory() + "Shaders/simple.frag");
    
    ui =            Shader(FileManager::assetsDirectory() + "Shaders/ui.vert",
                           FileManager::assetsDirectory() + "Shaders/ui.frag");
    
    uiTexture =     Shader(FileManager::assetsDirectory() + "Shaders/uiTexture.vert",
                           FileManager::assetsDirectory() + "Shaders/uiTexture.frag");
    
    uiMonochrome =  Shader(FileManager::assetsDirectory() + "Shaders/uiMonochrome.vert",
                           FileManager::assetsDirectory() + "Shaders/uiMonochrome.frag");
    
    colorVertices = Shader(FileManager::assetsDirectory() + "Shaders/colorVertices.vert",
                           FileManager::assetsDirectory() + "Shaders/colorVertices.frag");
    
    texture =       Shader(FileManager::assetsDirectory() + "Shaders/texture.vert",
                           FileManager::assetsDirectory() + "Shaders/texture.frag");
    
    sprite =        Shader(FileManager::assetsDirectory() + "Shaders/sprite.vert",
                           FileManager::assetsDirectory() + "Shaders/sprite.frag");
    
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
    
    Shader::sprite.use();
    Shader::sprite.setUniformProjectionMatrix(uiProjection);
}

void Shader::setUniformColor(const Color &color) {
    if (uniformColor == -1)
        uniformColor = glGetUniformLocation(program, "uniformColor");
    color.setToUniform(uniformColor);
}

void Shader::setUniformProjectionMatrix(const mat4 &projection) {
    if (uniformProjection == -1)
        uniformProjection = glGetUniformLocation(program, "uniformProjection");
    GL(glUniformMatrix4fv(uniformProjection, 1, false, &projection[0][0]));
}

void Shader::setUniformPosition(const Point &position) {
    if (uniformPosition == -1)
        uniformPosition = glGetUniformLocation(program, "uniformPosition");
    glUniform2f(uniformPosition, position.x, position.y);

}

