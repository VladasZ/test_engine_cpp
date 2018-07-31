//
//  BufferData.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

 #include <cstring>

#include "BufferData.hpp"

BufferData::BufferData(const GLfloat *vertData, GLuint vertSize)
:
vertSize(vertSize)
{
    this->vertData = (GLfloat *)malloc(vertSize);
    memcpy(this->vertData, vertData, vertSize);
}

BufferData::BufferData(const GLfloat *vertData, GLuint vertSize,
                       const GLushort *indData, GLuint indSize)
:
vertSize(vertSize),
indSize(indSize)
{
    this->vertData = (GLfloat *)malloc(vertSize);
    memcpy(this->vertData, vertData, vertSize);
    
    this->indData = (GLushort *)malloc(indSize);
    memcpy(this->indData, indData, indSize);
}

BufferData::~BufferData() {
    if (vertData != nullptr) free(vertData);
    if (indData != nullptr) free(indData);
}
