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
#include "Array.hpp"

class Buffer;
class OldView;

enum PathDrawMode {
    Fill,
    Stroke
};

class Path : public Drawable {
    
    Array<ui::Point> points;
    
//    BufferData* getBufferData() override;
    bool buffer_is_set = false;
    
    static Path* circle_with(const ui::Point& center, float radius, int precision);

public:
    
    float line_width = 1;
    PathDrawMode draw_mode;
    
    void draw() override;

    Path() = default;
    Path(const ui::Rect& rect);
    static Path* circle_with(const ui::Point& center, float radius);
    
    void add_point(float x, float y);
};
