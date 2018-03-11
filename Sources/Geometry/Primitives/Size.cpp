//
//  Size.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Size.hpp"
#include "GL.hpp"
#include "BufferData.hpp"

Size::Size(float width, float height) : width(width), height(height) { }

BufferData * Size::getData() const {
    
    GLfloat data[] = {
        0,     0,
        0,     height,
        width, height,
        width, 0
    };
    
    GLushort indices[] = { 0, 1, 3, 2 };
    
    return new BufferData(data,    sizeof(data),
                          indices, sizeof(indices));
}
