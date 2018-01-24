//
//  BufferData.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "Tools.hpp"

class Buffer;

class BufferData : public NonCopyable _MEMORY_MANAGED(BufferData) {
    
    GLfloat *vertData = nullptr;
    GLuint vertSize = 0;
    
    GLushort *indData = nullptr;
    GLuint indSize = 0;
    
    friend Buffer;
    
public:
    
    BufferData(GLfloat *vertData, GLuint vertSize);
    
    BufferData(GLfloat *vertData, GLuint vertSize,
               GLushort *indData,  GLuint indSize);
    
    ~BufferData();
};
