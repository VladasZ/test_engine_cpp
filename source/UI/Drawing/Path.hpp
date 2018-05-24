//
//  Path.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 09/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "Rect.hpp"
#include "Drawable.hpp"

class Buffer;
class View;

enum PathDrawMode {
    Fill,
    Stroke
};

class Path : public Drawable _MEMORY_MANAGED(Path) {
    
    vector<Point> points;
    
    BufferData *getBufferData() override;
    bool bufferIsSet = false;
    Point _origin;
    
    static Path *circleWith(const Point &center, float radius, int precision);

public:
    
    float lineWidth = 1;
    PathDrawMode drawMode;
    
    void draw() override;

    Path() = default;
    Path(const Rect &rect);
    static Path *circleWith(const Point &center, float radius);
    
    void addPoint(int x, int y);
    void addPoint(const Point &point);
    
    void setOrigin(const Point &origin);
};
