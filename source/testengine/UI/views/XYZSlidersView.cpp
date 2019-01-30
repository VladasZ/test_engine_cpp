//
//  XYZSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "XYZSlidersView.hpp"

XYZSlidersView::~XYZSlidersView() {
    delete  _x_slider;
    delete  _y_slider;
    delete  _z_slider;
}

void XYZSlidersView::_setup() {
    _x_slider = new ui::LabeledSliderView();
    _y_slider = new ui::LabeledSliderView();
    _z_slider = new ui::LabeledSliderView();

    add_subview({ _x_slider,
                  _y_slider,
                  _z_slider });

    _x_slider->set_caption("X");
    _y_slider->set_caption("Y");
    _z_slider->set_caption("Z");

#define XYZ_SET_VALUE(var, value) var = -1 + value * 2 * multiplier;

    _x_slider->on_value_changed.subscribe([&](float value){
        XYZ_SET_VALUE(position.x, value);
        on_change(position);
    });

    _y_slider->on_value_changed.subscribe([&](float value){
        XYZ_SET_VALUE(position.y, value);
        on_change(position);
    });

    _z_slider->on_value_changed.subscribe([&](float value){
        XYZ_SET_VALUE(position.z, value);
        on_change(position);
    });
}

void XYZSlidersView::_layout() {
    _calculate_absolute_frame();
    _layout_constraints();

    static const float margin = 4;
    const float width = (_frame.size.width - margin * 2) / 3;

    _x_slider->set_frame({ width * 0 + margin * 0, 0, width, _frame.size.height });
    _y_slider->set_frame({ width * 1 + margin * 1, 0, width, _frame.size.height });
    _z_slider->set_frame({ width * 2 + margin * 1, 0, width, _frame.size.height });

    _layout_subviews();
}
