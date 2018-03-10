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

class Path : public Drawable _MEMORY_MANAGED(Path) {
    
    vector<Point> points;
    
    BufferData *getBufferData() override;
    bool bufferIsSet = false;
    
public:
    
    float lineWidth = 1;
    
    void draw() override;

    
    Path() = default;
    Path(const Rect &rect);
    
    void addPoint(int x, int y);
    void addPoint(const Point &point);
};
