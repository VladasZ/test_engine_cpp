//
//  BufferData.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "Size.hpp"
#include "Array.hpp"

class Buffer;

class BufferData {
    
    GLfloat* vert_data;
    GLuint vert_size;
    
    GLushort* ind_data;
    GLuint ind_size;
    
    friend Buffer;
    
public:
    
    BufferData(const GLfloat* vert_data, GLuint vert_size);
    
    BufferData(const GLfloat* vert_data,  GLuint vert_size,
               const GLushort* ind_data,  GLuint ind_size);
    
    void set_indices(const Array<GLushort>&);
    
    static BufferData* from_size(const Size&);
    static BufferData* from_rect(const Rect&);
    static BufferData* from_rect_to_image(const Rect&);
    static BufferData* from_rect_to_framebuffer(const Rect&);

    ~BufferData();
};
