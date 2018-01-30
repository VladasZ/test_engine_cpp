//
//  BufferConfiguration.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "BufferConfiguration.hpp"
#include "Log.hpp"
#include "GL.hpp"

BufferConfiguration::BufferConfiguration(int firstParam, int secondParam, int thirdParam) {
    
    if (firstParam == 0) { //Error("Zero configuration");
        return; }
    
    if (secondParam > 0) size++;
    if (thirdParam > 0)  size++;
    
    configuration = (int *)malloc(sizeof(int) * size);
    
                         configuration[0] = firstParam;
    if (secondParam > 0) configuration[1] = secondParam;
    if (thirdParam  > 0) configuration[2] = thirdParam;
    
    for (int i = 0; i < size; i ++)
        vertexSize += configuration[i];
}

BufferConfiguration::~BufferConfiguration() {
    
    if (configuration != nullptr) free(configuration);
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
                
        glVertexAttribPointer(i,
                              attribureSize,
                              GL_FLOAT,
                              GL_FALSE,
                              vertexSize * sizeof(GLfloat),
                              (GLvoid*)(strideForIndex(i) * sizeof(GLfloat)));
        
        glEnableVertexAttribArray(i);
    }
}
