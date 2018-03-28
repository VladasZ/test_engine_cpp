//
//  Point.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Point.hpp"
#include <math.h>

Point::Point(float x, float y) : x(x), y(y) {
    
}

Point::Point(Direction direction, float length) {
    switch (direction) {
        case Direction::left:  x = -length; y =  0;      break;
        case Direction::right: x =  length; y =  0;      break;
        case Direction::up:    x =  0;      y = -length; break;
        case Direction::down:  x =  0;      y =  length; break;
        default: break;
    }
}

Point Point::onCircle(float radius, float angle, const Point &center) {
    return Point((radius / 2) * cos(angle) + center.x, (radius / 2) * sin(angle) + center.y);
}

bool Point::isZero() const {
    return x == 0 and y == 0;
}

float Point::length() const {
    return sqrt(x * x + y * y);
}

Point Point::withLength(float length) const {
    float ratio = length / this->length();
    return Point(x * ratio, y * ratio);
}

String Point::toString() const {
    return "x: "_s + x + " y: " + y;
}

Point Point::operator +(const Point &point) const {
    return Point(x + point.x, y + point.y);
}

void Point::operator +=(const Point &point) {
    x += point.x;
    y += point.y;
}

Point Point::operator -(const Point &point) const {
    return Point(x - point.x, y - point.y);
}

Point Point::operator *(float value) const {
    return Point(x * value, y * value);
}

void Point::operator *=(float value) {
    x *= value;
    y *= value;
}
