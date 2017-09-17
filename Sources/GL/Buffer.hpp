//
//  Buffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Types.h"
#include "GL.hpp"
#include "BufferData.hpp"

class Buffer {
    
    BufferData data;
    
    GLuint vertexArrayObject = 0;
    GLuint vertexBufferObject = 0;
    GLuint indexBufferObject = 0;
    
public:
    
    GLenum drawMode = GL_TRIANGLES;
    
    Buffer(const BufferData &data);
    
    Buffer(GLfloat *vertData, GLuint vertSize);
    
    Buffer(GLfloat *vertData, GLuint vertSize,
           GLushort *indData,  GLuint indSize);

    ~Buffer();

    void draw() const;
};
