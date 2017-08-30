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

Shader::Shader(const string &vertexPath, const string &fragmentPath) {
    
    program = ShaderCompiler::compile(vertexPath, fragmentPath);
}

void Shader::use() {
    
    glUseProgram(program);
}

void Shader::initialize() {
    
    simple = Shader(FileManager::assetsDirectory() + "Shaders/vert.vert",
                    FileManager::assetsDirectory() + "Shaders/frag.frag");
}
