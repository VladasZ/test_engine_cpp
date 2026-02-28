//
//  View.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/5/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <algorithm>

#include "ui.hpp"
#include "Log.hpp"
#include "View.hpp"
#include "Input.hpp"
#include "GLWrapper.hpp"
#include "ArrayUtils.hpp"
#include "FrameResizer.hpp"

using namespace ui;


View::View(const Rect& rect) : _frame(rect), place(ViewPlacer(this)) { }

View::~View() {
    for (auto view : _subviews) {
    	delete view;
	}
    disable_touch();
    disable_resize();
}

View* View::superview() const {
    return _superview;
}

const View::Array &View::subviews() const {
    return _subviews;
}

void View::add_subview(View* view) {
    view->_superview = this;
    _subviews.push_back(view);
    view->setup();
}

void View::remove_all_subviews() {
    for (auto view : _subviews) delete view;
    _subviews.clear();
}

void View::remove_from_superview() {
    cu::container::remove(_superview->_subviews, this);
    delete this;
}

void View::remove_last_subview() {
    delete _subviews.back();
    _subviews.pop_back();
}

Rect& View::edit_frame() {
    _needs_reposition = true;
    _needs_layout = true;
    for (auto view : _subviews) {
        view->_set_needs_reposition();
    }
    return _frame;
}

const Rect& View::absolute_frame() const {
    return _absolute_frame;
}

float View::content_width() const {
    return std::max(_frame.size.width, content_size.width);
}

float View::content_height() const {
    return std::max(_frame.size.height, content_size.height);
}

bool View::contains_global_point(const Point& point) const {
    return _absolute_frame.contains(point);
}

bool View::is_visible() const {
    if (is_hidden) return false;
    if (_superview == nullptr) return true;

    auto super = _superview;

    while (super) {
        if (super->is_hidden) return false;
        super = super->superview();
    }

    return true;
}

void View::_draw() {

    if (_superview == nullptr) {
        Fatal("Drawing view without superview");
    }

    if (is_hidden) return;
    if (_needs_reposition) {
        _calculate_absolute_frame();
        _needs_reposition = false;
    }
    if (_needs_layout) {
        on_layout();
        layout();
        _needs_layout = false;
    }
    if (clips) {
        GL::scissor_begin(_absolute_frame);
    }
    _draw_rect();
    for (auto view : _subviews) {
        view->_draw();
    }
    if (clips) {
        GL::scissor_end();
    }
}

void View::_set_needs_layout() {
    _needs_layout = true;
    for (auto view : _subviews) {
        view->_set_needs_reposition();
    }
}

void View::_set_needs_reposition() {
    _needs_reposition = true;
    for (auto view : _subviews) {
        view->_set_needs_reposition();
    }
}

void View::_draw_rect() const {
    if (!background_color.is_clear()) {
        config::drawer()->fill_rect(_absolute_frame, background_color);
    }
#ifdef DRAW_DEBUG_FRAMES
    if (draw_debug_frame) {
        config::drawer()->draw_rect(_absolute_frame, Color::turquoise);
    }
#endif
}

void View::_calculate_absolute_frame() {
    _absolute_frame = _frame;
    if (_superview) {
        _absolute_frame.origin += _superview->_absolute_frame.origin + _superview->content_offset;
    }
    if (_resize_enabled) {
        _resizer->update_edge_info();
    }
}

void View::enable_touch() {
    if (_touch_enabled) return;
    _touch_enabled = true;
    Input::subscribe_view(this);
}

void View::disable_touch() {
    if (!_touch_enabled) return;
    _touch_enabled = false;
    Input::unsubscribe_view(this);
}

void View::enable_resize() {
    if (_resize_enabled) return;
    _resize_enabled = true;
    static bool dummy = true;
    _resizer = new FrameResizer(_frame, _absolute_frame, dummy);
    Input::subscribe_resizable(this);
}

void View::disable_resize() {
    if (!_resize_enabled) return;
    _resize_enabled = false;
    delete _resizer;
    _resizer = nullptr;
    Input::unsubscribe_resizable(this);
}

View* View::dummy(const Rect& frame) {
    auto view = new View(frame);
    view->background_color = Color::random();
    return view;
}
