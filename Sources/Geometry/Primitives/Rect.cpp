//
//  Rect.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Rect.hpp"
#include "Window.hpp"
#include "BufferData.hpp"

Rect::Rect(float width, float height)
: size(Size(width, height))
{
    
}


Rect::Rect(float x, float y, float width, float height)
: origin(Point(x, y)), size(Size(width, height))
{
    
}

BufferData * Rect::getData() const {
    
    GLfloat rect[] = {
        origin.x,              origin.y,              
        origin.x,              size.height + origin.y,
        size.width + origin.x, size.height + origin.y,
        size.width + origin.x, origin.y
    };
    
    GLushort indices[] = { 0, 1, 2, 3 };
    
    return new BufferData(rect,    sizeof(rect),
                         indices, sizeof(indices));
}

string Rect::toString() const {
    
    return "x: " + to_string(origin.x) + " y: " + to_string(origin.y) +
    " width: " + to_string(size.width) + " height: " + to_string(size.width);
}

