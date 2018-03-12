//
//  Path.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Path.hpp"
#include "GL.hpp"
#include "BufferData.hpp"
#include "Buffer.hpp"
#include <math.h>

Path::Path(const Rect &rect) {
    points = {
              rect.origin,
        Point(rect.origin.x,                    rect.origin.y + rect.size.width),
        Point(rect.origin.x + rect.size.height, rect.origin.y + rect.size.width),
        Point(rect.origin.x + rect.size.height, rect.origin.y)
    };
}

Path * Path::circleWith(const Point &center, float radius, int precision) {
    auto path = new Path();
    float angleStep = M_PI * 2 / precision;
    
    for (int i = 0; i < precision; i++)
        path->points.push_back(Point::onCircle(radius, angleStep * i, center));
    
    return path;
}

Path * Path::circleWith(const Point &center, float radius) {
    return circleWith(center, radius, 40);
}

void Path::draw() {
    
    if (!bufferIsSet) { bufferIsSet = true;
        if (!_origin.isZero()) {
            auto pointsCopy = points;
            for (auto &point : points) point += _origin;
            setupBuffer();
            points = pointsCopy;
            return;
        }
        setupBuffer();
    }
    
    Shader::ui.use();
    Shader::ui.setUniformColor(color);
    
    GL(glLineWidth(lineWidth));
    
    buffer->drawMode = drawMode == Stroke ? GL_LINE_LOOP : GL_TRIANGLE_FAN;
    buffer->draw();
}

BufferData * Path::getBufferData() {
    int size = (int)(sizeof(float) * points.size() * 2);
    return new BufferData((float *)&points[0], size);
}

void Path::addPoint(int x, int y) {
    addPoint(Point(x, y));
}

void Path::addPoint(const Point &point) {
    points.push_back(point);
    bufferIsSet = false;
}

void Path::setOrigin(const Point &origin) {
    _origin = origin;
    bufferIsSet = false;
}
