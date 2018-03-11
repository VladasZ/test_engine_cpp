//
//  Rect.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Rect.hpp"
#include "Window.hpp"
#include "BufferData.hpp"

Rect::Rect() { }

Rect::Rect(float width, float height) : origin(Point(0, 0)), size(Size(width, height)) { }

Rect::Rect(const Size &_size) : origin(Point(0, 0)), size(_size) { }

Rect::Rect(float x, float y, float width, float height) : origin(Point(x, y)), size(Size(width, height)) { }

Rect& Rect::operator=(const Rect &r2) {
    origin = r2.origin;
    size = r2.size;
    return *this;
}

BufferData * Rect::getData() const {
    
    GLfloat rect[] = {
        origin.x,              origin.y,              
        origin.x,              size.height + origin.y,
        size.width + origin.x, size.height + origin.y,
        size.width + origin.x, origin.y
    };
    
    GLushort indices[] = { 0, 1, 3, 2 };
    
    return new BufferData(rect,    sizeof(rect),
                          indices, sizeof(indices));
}

float Rect::maxX() const { return origin.x + size.width; }

float Rect::maxY() const { return origin.y + size.height; }

bool Rect::contains(const Point &point) const {
    return  point.x > origin.x &&
            point.y > origin.y &&
           (point.x < origin.x + size.width) &&
           (point.y < origin.y + size.height);
}

Rect Rect::withZeroOrigin() const {
    return Rect(size.width, size.height);
}

String Rect::toString() const {
    return "x: " + to_string(origin.x) + " y: " + to_string(origin.y) +
    " width: " + to_string(size.width) + " height: " + to_string(size.width);
}

