//
//  Point.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

enum Direction {
    Right,
    Left,
    Up,
    Down
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

        Point withLength(float length) const;

        Direction directionX() const;

        Point operator +(const Point &point) const;
        void operator +=(const Point &point);

        Point operator -(const Point &point) const;
        void operator -=(const Point &point);

        Point operator *(float value) const;
        void operator *=(float value);

        static const Point one;
    };
}

using namespace TestEngine;