//
//  ViewPlacer.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 22/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "View.hpp"

using namespace ui;


ViewPlacer::ViewPlacer(View* view) : _view(view), _frame(view->_frame) {

}

void ViewPlacer::set_center(const Point& center) const {
	_frame.set_center(center);
	_view->_set_needs_reposition();
}

void ViewPlacer::as(View* view) const {
	_view->edit_frame() = view->_frame;
}

void ViewPlacer::as_background() const {
    _view->edit_frame() = _view->_superview->frame().with_zero_origin();
}

void ViewPlacer::at_center() const {
    _frame.origin.x = _view->_superview->content_width() / 2 - _frame.size.width / 2;
    _frame.origin.y = _view->_superview->content_height() / 2 - _frame.size.height / 2;
    _view->_set_needs_reposition();
}

void ViewPlacer::center_ver() const {
    _frame.origin.y = _view->_superview->content_height() / 2 - _frame.size.height / 2;
    _view->_set_needs_reposition();
}

void ViewPlacer::center_hor() const {
    _frame.origin.x = _view->_superview->content_width() / 2 - _frame.size.width / 2;
    _view->_set_needs_reposition();
}

void ViewPlacer::at_bottom(float margin) const {
    _frame.set_center(_view->_superview->frame().center());
    _frame.origin.y = _view->_superview->content_height() - _frame.size.height - margin;
    _view->_set_needs_reposition();
}

void ViewPlacer::l(float margin) const {
    _frame.origin.x = margin;
    _view->_set_needs_reposition();
}

void ViewPlacer::r(float margin) const {
    _frame.origin.x = _view->_superview->frame().size.width - _frame.size.width - margin;
    _view->_set_needs_reposition();
}

void ViewPlacer::br(float margin) const {
    _frame.origin.x = _view->_superview->frame().size.width - _frame.size.width - margin;
    _frame.origin.y = _view->_superview->content_height() - _frame.size.height - margin;
    _view->_set_needs_reposition();
}

void ViewPlacer::bl(float margin) const {
    _frame.origin.x = margin;
    _frame.origin.y = _view->_superview->content_height() - _frame.size.height - margin;
    _view->_set_needs_reposition();
}

void ViewPlacer::tr(float margin) const {
    _frame.origin.x = _view->_superview->content_width() - _frame.size.width - margin;
    _frame.origin.y = margin;
    _view->_set_needs_reposition();
}

void ViewPlacer::place_at_left_half(bool preserve_height) const {
    if (preserve_height) {
        _frame.origin.x = 0;
        _frame.size.width = _view->_superview->frame().size.width / 2;
    }
    else {
        _frame.origin = { };
        _frame.size = { _view->_superview->frame().size.width / 2, _view->_superview->frame().size.height };
    }
    _view->_set_needs_layout();
}

void ViewPlacer::place_at_right_half(bool preserve_height) const {
    if (preserve_height) {
        _frame.origin.x = _view->_superview->frame().size.width / 2;
        _frame.size.width = _view->_superview->frame().size.width / 2;
    }
    else {
        _frame.origin = { _view->_superview->frame().size.width / 2, 0 };
        _frame.size = { _view->_superview->frame().size.width / 2, _view->_superview->frame().size.height };
    }
    _view->_set_needs_layout();
}

void ViewPlacer::place_at_top_half() const {
    _frame = { 0,
               0,
               _view->_superview->frame().size.width,
               _view->_superview->frame().size.height / 2
    };
    _view->_set_needs_layout();
}

void ViewPlacer::place_at_bottom_half() const {
    _frame = { 0,
               _view->_superview->frame().size.height / 2,
               _view->_superview->frame().size.width,
               _view->_superview->frame().size.height / 2
    };
    _view->_set_needs_layout();
}

void ViewPlacer::same_height(View* view) const {
    _frame.size.height = view->frame().size.height;
    _view->_set_needs_layout();
}

void ViewPlacer::to(View* view, Edge edge, float margin, Edge alignment) const {

    const auto& target_frame = view->frame();

    _frame.set_center(target_frame.center());

    if (edge == Edge::Right) {
        _frame.origin.x = target_frame.max_x() + margin;
    }
    else if (edge == Edge::Left) {
        _frame.origin.x = target_frame.min_x() - margin - _frame.size.width;
    }
    else if (edge == Edge::Top) {
        _frame.origin.y = target_frame.min_y() - margin - _frame.size.height;
    }
    else if (edge == Edge::Bottom) {
        _frame.origin.y = target_frame.max_y() + margin;
    }
    else {
        Fatal("Invalid edge");
    }

    if (alignment == Edge::Center) {
        _view->_set_needs_reposition();
        return;
    }

    if (alignment == Edge::Left) {
        _frame.origin.x = target_frame.origin.x;
    }
    else if (alignment == Edge::Right) {
        _frame.origin.x = target_frame.max_x() - _frame.size.width;
    }
    else if (alignment == Edge::Top) {
        _frame.origin.y = target_frame.origin.y;
    }
    else if (alignment == Edge::Bottom) {
        _frame.origin.y = target_frame.max_y() - _frame.size.height;
    }
    else {
        Fatal("Invalid alignment");
    }

    _view->_set_needs_reposition();

}
