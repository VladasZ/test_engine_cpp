//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "GL.hpp"

Buffer::Buffer(const int &size, const void *data, UInt type) : type(type) {
    
    this->data = data;
    
    glGenBuffers(1, &id);
    glBindBuffer(type, id);
    glBufferData(type, size,
                 data, GL_STATIC_DRAW);
}

void Buffer::bind() {
    
    glBindBuffer(type, id);
}

void Buffer::setVertexPointer(const int &location) const {
    
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          7 * sizeof(GLfloat),
                          0);
}

void Buffer::setColorPointer(const int &location) const {
    
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location,
                          4,
                          GL_FLOAT,
                          GL_FALSE,
                          7 * sizeof(GLfloat),
                          (void *)(sizeof(GLfloat) * 3));
}
