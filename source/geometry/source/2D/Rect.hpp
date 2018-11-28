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

class Rect {
    
public:
    
    Point origin;
    Size  size;
    
    Rect() = default;
	Rect(const Size &size);
    Rect(float width, float height);
    Rect(float x, float y, float width, float height);
    
    Rect& operator = (const Rect& r2);

    float max_x() const;
    float max_y() const;
    
    bool contains(const Point& point) const;
    
    Rect with_zero_origin() const;
};
