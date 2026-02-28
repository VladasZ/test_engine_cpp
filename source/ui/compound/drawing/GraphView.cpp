//
//  GraphView.сpp
//  ui
//
//  Created by Vladas Zakrevskis on 4/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "GraphView.hpp"

using namespace ui;


GraphView::~GraphView() {
    delete _path;
}

size_t GraphView::points_size() const {
    return _points_size;
}

void GraphView::set_points_size(size_t size) {
    _points_size = size;
    _recalculate_graph();
}

void GraphView::add_point(float point) {
    if (_points.size() > _points_size) reset();

    _points.push_back(point);

    if (auto_ranges) {
        if (point > _range.max()) {
            _range.set_max(point);
            _recalculate_graph();
            return;
        }
        else if (point < _range.min()) {
            _range.set_min(point);
            _recalculate_graph();
            return;
        }
    }

     _path->add_point({ _points.size() * _delta(), _frame.size.height - _range.convert(point) });
    _drawing_view->remove_all_paths();
    _drawing_view->add_path(_path, graph_color, PathData::DrawMode::Outline);
}

void GraphView::reset() {
    _path->clear();
    _points.clear();
    _drawing_view->remove_all_paths();
}

void GraphView::reset_ranges() {
    if (!auto_ranges) return;
    reset();
    _range.set_min(std::numeric_limits<float>::max());
    _range.set_max(std::numeric_limits<float>::min());
}

void GraphView::set_range_min(float min) {
    _range.set_min(min);
}

void GraphView::set_range_max(float max) {
    _range.set_max(max);
}


void GraphView::setup() {
    _path = new gm::PointsPath();
    add_subview(_drawing_view = new DrawingView());
}

void GraphView::layout() {
    _drawing_view->edit_frame() = _frame.with_zero_origin();
    _range.set_target_max(_frame.size.height);
    _recalculate_graph();
}

float GraphView::_delta() const {
    return _frame.size.width / _points_size;
}

void GraphView::_recalculate_graph() {
    _path->clear();
    for (size_t i = 0; i < _points.size(); i++) {
        _path->add_point({ i * _delta(), _frame.size.height - _range.convert(_points[i]) });
    }
    _drawing_view->remove_all_paths();
    _drawing_view->add_path(_path, graph_color);
}
