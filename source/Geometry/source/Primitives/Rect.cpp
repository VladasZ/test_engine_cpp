//
//  Rect.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Rect.hpp"
#include "System.hpp"

Rect::Rect(float width, float height) : size(Size(width, height)) { }

Rect::Rect(const Size &_size) : size(_size) { }

Rect::Rect(float x, float y, float width, float height) : origin(Point(x, y)), size(Size(width, height)) { }

Rect& Rect::operator=(const Rect &r2) {
    origin = r2.origin;
    size = r2.size;
    return* this;
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
	return { size.width, size.height };
}

String Rect::toString() const {
    return "x: "_s +  origin.x  +      " y: " + origin.y +
      " width: "   + size.width + " height: " + size.width;
}

Rect Rect::random() {
    static const int size = 300;
    return {
        (float)System::random(size),
        (float)System::random(size),
        (float)System::random(size),
        (float)System::random(size)
    };
}
