//
//  Point.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/16/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Point.hpp"

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

String Point::toString() const {
    
    return to_string(x) + " " + to_string(y);
}

Point Point::operator +(const Point &point) const {
    
    return Point(x + point.x, y + point.y);
}

void Point::operator +=(const Point &point) {
    
    x += point.x;
    y += point.y;
}
