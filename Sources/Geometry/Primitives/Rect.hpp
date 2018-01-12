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
#include "STL.hpp"

class BufferData;

class Rect {
    
public:
    
    Point origin;
    Size size;
    
    Rect() = default;
    Rect(float width, float height);
    Rect(float x, float y, float width, float height);
    
    string toString() const;
    
    BufferData *getData() const;
};
