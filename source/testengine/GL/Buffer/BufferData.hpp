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
    
    GLfloat* vert_data = nullptr;
    GLuint vert_size = 0;
    
    GLushort* ind_data = nullptr;
    GLuint ind_size = 0;
    
    friend Buffer;
    
public:
    
    BufferData(const GLfloat* vert_data, GLuint vert_size);
    
    BufferData(const GLfloat* vert_data,  GLuint vert_size,
               const GLushort* ind_data,  GLuint ind_size);
    
    BufferData* setIndices(const Array<GLushort>& indices);
    
	static BufferData* from_size(const ui::Size& size);
	static BufferData* from_rect(const ui::Rect& rect);
	static BufferData* from_rect_to_image(const ui::Rect& rect);
	static BufferData* from_rect_to_framebuffer(const ui::Rect& rect);

    ~BufferData();
};
