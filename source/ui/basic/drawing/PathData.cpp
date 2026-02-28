//
//  PathData.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/29/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "UIDrawer.hpp"
#include "PathData.hpp"

using namespace ui;
using namespace gm;

PathData::PathData(PointsPath* path, void* data, const Color& color, DrawMode draw_mode)
: _path(path), _color(color), _data(data), draw_mode(draw_mode) {

}

PathData::~PathData() {
    ui::config::drawer()->free_path_data(this);
}

const PointsPath* PathData::path() const {
    return _path;
}

void* PathData::data() const {
    return _data;
}
