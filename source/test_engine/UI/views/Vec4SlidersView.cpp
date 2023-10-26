//
//  Vec4SlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/18/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"

#include "Vec4SlidersView.hpp"

#define SET_VALUE(var, val) var = (-1 + val * 2 * multiplier);


Vec4SlidersView::~Vec4SlidersView() { }

void Vec4SlidersView::setup() {

    init_view(_x_slider);
    init_view(_y_slider);
    init_view(_z_slider);
    init_view(_w_slider);

    _x_slider->set_caption("X");
    _y_slider->set_caption("Y");
    _z_slider->set_caption("Z");
    _w_slider->set_caption("W");

    _x_slider->set_slider_color(gm::Color::red);
    _y_slider->set_slider_color(gm::Color::green);
    _z_slider->set_slider_color(gm::Color::blue);
    _w_slider->set_slider_color(gm::Color::turquoise);

    _x_slider->slider_view->on_value_changed = [&](float value) {
        SET_VALUE(position.x, value);
        on_change(position);
    };

    _y_slider->slider_view->on_value_changed = [&](float value) {
        SET_VALUE(position.y, value);
        on_change(position);
    };

    _z_slider->slider_view->on_value_changed = [&](float value) {
        SET_VALUE(position.z, value);
        on_change(position);
    };

    _w_slider->slider_view->on_value_changed = [&](float value) {
        SET_VALUE(position.w, value);
        on_change(position);
    };
}

void Vec4SlidersView::layout() {

    static const float margin = 4;
    const float width = (_frame.size.width - margin * 2) / 4;

    _x_slider->edit_frame() = {width * 0 + margin * 0, 0, width, _frame.size.height };
    _y_slider->edit_frame() = {width * 1 + margin * 1, 0, width, _frame.size.height };
    _z_slider->edit_frame() = {width * 2 + margin * 1, 0, width, _frame.size.height };
    _w_slider->edit_frame() = {width * 3 + margin * 1, 0, width, _frame.size.height };

}
