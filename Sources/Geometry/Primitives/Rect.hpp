//
//  Rect.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "Size.hpp"

class BufferData;

class Rect //MEMORY_MANAGED(Rect)
{
    
public:
    
    float &x;
    float &y;
    float &width;
    float &height;
    
    Point origin;
    Size size;
    
    Rect();
    Rect(float width, float height);
    Rect(const Size &size);
    Rect(float x, float y, float width, float height);
    
    Rect& operator=(const Rect &r2);

    float maxX() const;
    float maxY() const;
    
    bool contains(const Point &point) const;
    
    Rect withZeroOrigin() const;
    
    String toString() const;
    
    BufferData *getData() const;
};
