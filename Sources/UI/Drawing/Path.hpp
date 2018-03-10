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

class Buffer;

class Path MEMORY_MANAGED(Path) {
    
    vector<Point> points;
    
    Buffer *buffer = nullptr;

    
public:
    
    Path() = default;
    Path(const Rect &rect);
    
    void addPoint(const Point &point);
    
};
