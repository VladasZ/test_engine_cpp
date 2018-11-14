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
    
    GLfloat* vertData = nullptr;
    GLuint vertSize = 0;
    
    GLushort* indData = nullptr;
    GLuint indSize = 0;
    
    friend Buffer;
    
public:
    
    BufferData(const GLfloat* vertData, GLuint vertSize);
    
    BufferData(const GLfloat* vertData,  GLuint vertSize,
               const GLushort* indData,  GLuint indSize);
    
    BufferData* setIndices(const Array<GLushort>& indices);
    
	static BufferData* fromSize(const Size& size);
	static BufferData* fromRect(const Rect& rect);
	static BufferData* fromRectToImage(const Rect& rect);
	static BufferData* fromRectToFramebuffer(const Rect& rect);

    ~BufferData();
};
