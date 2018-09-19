//
//  BufferConfiguration.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "BufferConfiguration.hpp"
#include "GL.hpp"
#include "Debug.hpp"
#include "Log.hpp"

BufferConfiguration::BufferConfiguration(int firstParam, int secondParam, int thirdParam) {
    
    if (firstParam == 0) { Error("Zero configuration"); return; }
    
                                 configuration[0] = firstParam;
    if (secondParam > 0) size++; configuration[1] = secondParam;
    if (thirdParam  > 0) size++; configuration[2] = thirdParam;
    
    for (int i = 0; i < size; i ++)
        vertexSize += configuration[i];
}

int BufferConfiguration::strideForIndex(int index) const {
    
    if (index == 0) return 0;
    
    int stride = vertexSize;
    
    for (int i = size - 1; i >= index; i--)
        stride -= configuration[i];
    
    return stride;
}

void BufferConfiguration::setPointers() const {
    
    for (int i = 0; i < size; i++) {
        
        int attribureSize = configuration[i];
        
        GL(glEnableVertexAttribArray(i));
        
        GL(glVertexAttribPointer(i,
                                 attribureSize,
                                 GL_FLOAT,
                                 GL_FALSE,
                                 vertexSize* sizeof(GLfloat),
                                 (GLvoid*)(strideForIndex(i)* sizeof(GLfloat))));
    }
}

const BufferConfiguration BufferConfiguration::_2   = { 2, 0, 0 };
const BufferConfiguration BufferConfiguration::_2_2 = { 2, 2, 0 };
const BufferConfiguration BufferConfiguration::_3   = { 3, 0, 0 };
const BufferConfiguration BufferConfiguration::_3_4 = { 3, 4, 0 };
