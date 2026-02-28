//
//  FrameResizer.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Input.hpp"
#include "FrameResizer.hpp"

using namespace ui;
using namespace gm;


FrameResizer::FrameResizer(gm::Rect& frame, gm::Rect& absolute_frame, bool& needs_layout)
: _frame(frame), _absolute_frame(absolute_frame), _needs_layout(needs_layout) { }

Edge FrameResizer::get_edge(const Point& point) {

    uint8_t edge = 0;

    if (!_absolute_frame.contains_with_edge(point, EdgeInfo::width / 2)) {
        return Edge::None;
    }

    if (point.x >= _edge_info.left_min && point.x <= _edge_info.left_max) {
        edge += static_cast<uint8_t>(Edge::Left);
    }

    if (point.x >= _edge_info.right_min && point.x <= _edge_info.right_max) {
        edge += static_cast<uint8_t>(Edge::Right);
    }

    if (point.y >= _edge_info.top_min && point.y <= _edge_info.top_max) {
        edge += static_cast<uint8_t>(Edge::Top);
    }

    if (point.y >= _edge_info.bottom_min && point.y <= _edge_info.bottom_max) {
        edge += static_cast<uint8_t>(Edge::Bottom);
    }

    _current_edge = static_cast<Edge>(edge);

    return _current_edge;
}

void FrameResizer::on_touch(ui::Touch* touch) {

    if (touch->is_began()) {
        _initial_touch = touch->position;
        return;
    }

    if (_current_edge == Edge::None) {
        _frame.origin += touch->position - _initial_touch;
    } else {
        _frame.set_edge(_current_edge, touch->position);
    }

    _needs_layout = true;
    _initial_touch = touch->position;

}

void FrameResizer::update_edge_info() {

    _edge_info.left_min   = _absolute_frame.origin.x - EdgeInfo::width / 2;
    _edge_info.left_max   = _absolute_frame.origin.x + EdgeInfo::width / 2;

    _edge_info.right_min  = _absolute_frame.origin.x + _absolute_frame.size.width - EdgeInfo::width / 2;
    _edge_info.right_max  = _absolute_frame.origin.x + _absolute_frame.size.width + EdgeInfo::width / 2;

    _edge_info.top_min    = _absolute_frame.origin.y - EdgeInfo::width / 2;
    _edge_info.top_max    = _absolute_frame.origin.y + EdgeInfo::width / 2;

    _edge_info.bottom_min = _absolute_frame.origin.y + _absolute_frame.size.height - EdgeInfo::width / 2;
    _edge_info.bottom_max = _absolute_frame.origin.y + _absolute_frame.size.height + EdgeInfo::width / 2;

}
