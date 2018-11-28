//
//  Point.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <cmath>

#include "Point.hpp"

Point::Point(float x, float y) : x(x), y(y) { }

Point::Point(Direction direction, float length) {
    switch (direction) {
        case Direction::Left:  x = -length; y =  0;      break;
        case Direction::Right: x =  length; y =  0;      break;
        case Direction::Up:    x =  0;      y = -length; break;
        case Direction::Down:  x =  0;      y =  length; break;
        default: break;
    }
}

Point Point::on_circle(float radius, float angle, const Point &center) {
	return { (radius / 2) * cos(angle) + center.x, (radius / 2) * sin(angle) + center.y };
}

float Point::angle() const {
    return atan2(y, x);
}

bool Point::is_zero() const {
    return x == 0 && y == 0;
}

float Point::length() const {
    return static_cast<float>(sqrt(x * x + y * y));
}

Point Point::with_length(float length) const {
    const float ratio = length / this->length();
	return { x * ratio, y * ratio };
}

Direction Point::directionX() const {
    return x > 0 ? Direction::Right : Direction::Left;
}

Point Point::operator + (const Point &point) const {
	return { x + point.x, y + point.y };
}

void Point::operator += (const Point &point) {
    x += point.x;
    y += point.y;
}

Point Point::operator - (const Point &point) const {
	return { x - point.x, y - point.y };
}

void Point::operator -= (const Point &point) {
    x -= point.x;
    y -= point.y;
}

Point Point::operator * (float value) const {
	return { x * value, y * value };
}

void Point::operator *= (float value) {
    x *= value;
    y *= value;
}
