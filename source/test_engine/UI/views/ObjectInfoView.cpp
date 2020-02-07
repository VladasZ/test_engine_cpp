//
//  XYZSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"

#include "XYZSlidersView.hpp"

using namespace gm;
using namespace cu;

#define XYZ_SET_VALUE(var, val) var = (-1 + val * 2 * multiplier);

XYZSlidersView::~XYZSlidersView() {
    delete  sliders.x;
    delete  sliders.y;
    delete  sliders.z;
}

void XYZSlidersView::_setup() {
    sliders.x = new ui::LabeledSliderView();
    sliders.y = new ui::LabeledSliderView();
    sliders.z = new ui::LabeledSliderView();

    add_subviews({ sliders.x,
                   sliders.y,
                   sliders.z });

    sliders.x->set_caption("X");
    sliders.y->set_caption("Y");
    sliders.z->set_caption("Z");

    sliders.x->set_slider_color(gm::Color::red);
    sliders.y->set_slider_color(gm::Color::green);
    sliders.z->set_slider_color(gm::Color::blue);

    sliders.x->slider_view->on_value_changed = [&](float value) {
        XYZ_SET_VALUE(position.x, value);
        on_change(position);
    };

    sliders.y->slider_view->on_value_changed = [&](float value) {
        XYZ_SET_VALUE(position.y, value);
        on_change(position);
    };

    sliders.z->slider_view->on_value_changed = [&](float value) {
        XYZ_SET_VALUE(position.z, value);
        on_change(position);
    };
}

void XYZSlidersView::_layout() {
    _calculate_absolute_frame();

    static const float margin = 4;
    const float width = (_frame.size.width - margin * 2) / 3;

    sliders.x->edit_frame() = {width * 0 + margin * 0, 0, width, _frame.size.height };
    sliders.y->edit_frame() = {width * 1 + margin * 1, 0, width, _frame.size.height };
    sliders.z->edit_frame() = {width * 2 + margin * 1, 0, width, _frame.size.height };

    _layout_subviews();
}
