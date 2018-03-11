//
//  Point.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

namespace TestEngine {
    
    class Point {
        
    public:
                
        float x = 0, y = 0;
                
        Point() = default;
        Point(float x, float y);
                
        float angle() const;
        bool isZero() const;
        float length() const;
        
        Point normalized() const;
        float distanceTo(const Point &point) const;
        Point withLength(float length) const;
        float angleWith(const Point &point) const;
        float projectionTo(const Point &point) const;
        
        String toString() const;
        
        Point operator +(const Point &point) const;
        void operator +=(const Point &point);
                
        static const Point one;
    };
}

using namespace TestEngine;
