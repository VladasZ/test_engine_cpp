//
//  BufferData.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "BufferData.hpp"
#include <string.h>

BufferData::BufferData(GLfloat *vertData, GLuint vertSize)
:
vertSize(vertSize)
{
    this->vertData = (GLfloat *)malloc(vertSize);
    
    memcpy(this->vertData, vertData, vertSize);
}

BufferData::BufferData(GLfloat *vertData, GLuint vertSize,
               GLushort *indData,  GLuint indSize)
:
vertData(vertData), vertSize(vertSize),
indData(indData), indSize(indSize)
{
    this->vertData = (GLfloat *)malloc(vertSize);
    memcpy(this->vertData, vertData, vertSize);
    
    this->indData = (GLushort *)malloc(indSize);
    memcpy(this->indData, indData, indSize);
}

BufferData::~BufferData() {
    
    free(vertData);
    if (indData != nullptr) free(indData);
}
