//
//  Point.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Types.h"
#include "STL.hpp"

namespace TestEngine {
    
    class Point {
        
    public:
                
        Float x = 0, y = 0;
                
        Point() = default;
        Point(Float x, Float y);
                
        Float angle() const;
        bool isZero() const;
        Float length() const;
        
        Point normalized() const;
        Float distanceTo(const Point &point) const;
        Point withLength(Float length) const;
        Float angleWith(const Point &point) const;
        Float projectionTo(const Point &point) const;
        
        string toString() const;
        
        Point operator +(const Point &point) const;
        void operator +=(const Point &point);
                
        static const Point one;
    };
}

using namespace TestEngine;
