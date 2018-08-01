//
//  BufferData.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "Memory.hpp"

class Buffer;

class BufferData MEMORY_MANAGED(BufferData) {
    
    GLfloat* vertData = nullptr;
    GLuint vertSize = 0;
    
    GLushort* indData = nullptr;
    GLuint indSize = 0;
    
    friend Buffer;
    
public:
    
    BufferData(const GLfloat* vertData, GLuint vertSize);
    
    BufferData(const GLfloat* vertData,  GLuint vertSize,
               const GLushort* indData,  GLuint indSize);
    
    ~BufferData();
};
