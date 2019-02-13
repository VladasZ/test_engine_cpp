//
//  BufferConfiguration.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "GL.hpp"
#include "Debug.hpp"
#include "BufferConfiguration.hpp"

BufferConfiguration::BufferConfiguration(uint8_t first_param, uint8_t second_param, uint8_t third_param) {
    
    if (first_param == 0) {
        Error("Zero BufferConfiguration");
        throw "Zero BufferConfiguration";
    }
    
                                  configuration[0] = first_param;
    if (second_param > 0) size++; configuration[1] = second_param;
    if (third_param  > 0) size++; configuration[2] = third_param;
    
    for (uint8_t i = 0; i < size; i ++)
        vertex_size += configuration[i];
}

uint8_t BufferConfiguration::stride_for_index(uint8_t index) const {
    
    if (index == 0)
        return 0;
    
    uint8_t stride = vertex_size;
    
    for (uint8_t i = size - 1; i >= index; i--)
        stride -= configuration[i];
    
    return stride;
}

void BufferConfiguration::set_pointers() const {
    
    for (uint8_t i = 0; i < size; i++) {
        
        int attribureSize = configuration[i];
        
        GL(glEnableVertexAttribArray(i));
        
        GL(glVertexAttribPointer(i,
                                 attribureSize,
                                 GL_FLOAT,
                                 GL_FALSE,
                                 vertex_size* sizeof(GLfloat),
                                 reinterpret_cast<GLvoid*>((stride_for_index(i) * sizeof(GLfloat)))));
    }
}

const BufferConfiguration BufferConfiguration::_2   = { 2, 0, 0 };
const BufferConfiguration BufferConfiguration::_2_2 = { 2, 2, 0 };
const BufferConfiguration BufferConfiguration::_3   = { 3, 0, 0 };
const BufferConfiguration BufferConfiguration::_3_3 = { 3, 3, 0 };
const BufferConfiguration BufferConfiguration::_3_4 = { 3, 4, 0 };
