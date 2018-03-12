//
//  Point.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

enum Direction {
    right,
    left,
    up,
    down
};

namespace TestEngine {
    
    class Point {
        
    public:
                
        float x = 0, y = 0;
                
        Point() = default;
        Point(float x, float y);
        Point(Direction direction, float length = 1);
        
        static Point onCircle(float radius, float angle, const Point &center);
                
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
