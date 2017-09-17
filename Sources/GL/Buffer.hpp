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

class Buffer {
    
    GLfloat *vertData = nullptr;
    GLuint vertSize = 0;
    
    GLushort *indData = nullptr;
    GLuint indSize = 0;
    
    GLuint VBO;
    GLuint VAO;
    
public:
    
    GLenum drawMode = GL_TRIANGLES;
    
    Buffer(GLfloat *vertData, GLuint vertSize);
    
    Buffer(GLfloat *vertData, GLuint vertSize,
           GLushort *indData,  GLuint indSize);

    void draw() const;
};
