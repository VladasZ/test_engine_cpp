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
#include "BufferConfiguration.hpp"

class Buffer {
    
    BufferData data;
    
    GLuint vertexArrayObject = 0;
    GLuint vertexBufferObject = 0;
    GLuint indexBufferObject = 0;
    
public:
    
    GLenum drawMode = GL_TRIANGLE_STRIP;
    
    Buffer(const BufferData &data, const BufferConfiguration &configuration);
    
    Buffer(GLfloat *vertData, GLuint vertSize, const BufferConfiguration &configuration);
    
    Buffer(GLfloat *vertData, GLuint vertSize,
           GLushort *indData,  GLuint indSize,
           const BufferConfiguration &configuration);

    ~Buffer();
    
    void setPointers(UInt firstParam, UInt secondParam = 0, UInt thirdParam = 0) const;
    void setData(const BufferData &data);
    

    void draw() const;
};
