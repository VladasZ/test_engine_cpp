//
//  PathData.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/29/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "PointsPath.hpp"

namespace ui {

class PathData {

    gm::PointsPath* _path;
    gm::Color _color;
    void* _data;

public:

    enum class DrawMode {
        Outline,
        Fill
    };

public:

    DrawMode draw_mode;

    PathData(gm::PointsPath*, void*, const gm::Color& = gm::Color::green, DrawMode drawMode = DrawMode::Outline);
    ~PathData();

    const gm::PointsPath* path() const;

    const gm::Color& color() const { return _color; }

    void* data() const;

};

}
