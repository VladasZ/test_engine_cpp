//
//  Shader.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Shader.hpp"
#include "FileManager.hpp"
#include "ShaderCompiler.hpp"
#include "GL.hpp"

Shader Shader::simple;
Shader Shader::colorVertices;

Shader::Shader(const string &vertexPath, const string &fragmentPath) {
    
    program = ShaderCompiler::compile(vertexPath, fragmentPath);
    
    uniformColor = glGetUniformLocation(program, "uniformColor");
}

void Shader::use() const {
    
    glUseProgram(program);
}

void Shader::initialize() {
    
    simple = Shader(FileManager::assetsDirectory() + "Shaders/simple.vert",
                    FileManager::assetsDirectory() + "Shaders/simple.frag");
    
    colorVertices = Shader(FileManager::assetsDirectory() + "Shaders/colorVertices.vert",
                           FileManager::assetsDirectory() + "Shaders/colorVertices.frag");
}
