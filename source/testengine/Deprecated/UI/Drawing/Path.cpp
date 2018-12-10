//
//  Path.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <math.h>

#include "Path.hpp"
#include "GL.hpp"
#include "Debug.hpp"
#include "BufferData.hpp"
#include "Buffer.hpp"
#include "Window.hpp"
#include "Geometry.hpp"

Path::Path(const ui::Rect &rect) {
    points = {
              rect.origin,
		ui::Point(rect.origin.x,                    rect.origin.y + rect.size.width),
		ui::Point(rect.origin.x + rect.size.height, rect.origin.y + rect.size.width),
		ui::Point(rect.origin.x + rect.size.height, rect.origin.y)
    };
}

Path* Path::circle_with(const ui::Point& center, float radius, int precision) {
    auto path = new Path();
    float angle_step = pi2<float> / precision;

    for (int i = 0; i < precision; i++)
        path->points.emplace_back(ui::Point::on_circle(radius, angle_step * i, center));

    return path;
}

Path* Path::circle_with(const ui::Point& center, float radius) {
    return circle_with(center, radius, 50);
}

void Path::draw() {
    
   /* if (!bufferIsSet) { 
        bufferIsSet = true;
        setupBuffer();
    }

    Shader::uiPath.setUniformColor(color);

    GL(glLineWidth(lineWidth));

    buffer->drawMode = drawMode == Stroke ? GL_LINE_LOOP : GL_TRIANGLE_FAN;
    buffer->draw();*/
}

//BufferData* Path::getBufferData() {
//    int size = (int)(sizeof(Point) * points.size());
//    return new BufferData((float*)&points[0], size);
//}

void Path::add_point(float x, float y) {
    points.emplace_back(x, y);
    buffer_is_set = false;
}
