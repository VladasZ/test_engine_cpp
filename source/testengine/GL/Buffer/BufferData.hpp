//
//  BufferData.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "GL.hpp"
#include "Size.hpp"

class Buffer;

class BufferData {
    
    std::vector<GLfloat> vertices;
    std::vector<GLushort> indices;
    
    friend Buffer;
    
public:
        
    BufferData(const std::vector<GLfloat>& vertices, const std::vector<GLushort>& indices = { });
    
    const char* to_string(unsigned int new_line = 3) const;
    
    static BufferData* from_size(const Size&);
    static BufferData* from_rect(const Rect&);
    static BufferData* from_rect_to_image(const Rect&);
    static BufferData* from_rect_to_framebuffer(const Rect&);
};
