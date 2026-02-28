//
//  DrawingView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "UIDrawer.hpp"
#include "DrawingView.hpp"

using namespace ui;


DrawingView::~DrawingView() {
    for (auto path : _paths) {
        delete path;
    }
}

const DrawingView::Paths& DrawingView::paths() const {
    return _paths;
}

void DrawingView::add_path(gm::PointsPath* path, const gm::Color& color, PathData::DrawMode draw_mode) {
    _paths.push_back(ui::config::drawer()->initialize_path_data(path, color, draw_mode));
}

void DrawingView::remove_all_paths() {
    for (auto path : _paths) {
        delete path;
    }
    _paths.clear();
}

void DrawingView::_draw() {
    View::_draw();
    for (auto path : _paths) {
        ui::config::drawer()->draw_path_in_rect(path, absolute_frame());
    }
}
