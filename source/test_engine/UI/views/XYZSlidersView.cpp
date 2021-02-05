//
//  XYZSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "XYZSlidersView.hpp"


using namespace te;
using namespace gm;
using namespace cu;
using namespace ui;


XYZSlidersView::~XYZSlidersView() { }

void XYZSlidersView::set_range(float min, float max) {
    for (auto view : sliders) {
        view->slider_view->conversion.set_target_min(min);
        view->slider_view->conversion.set_target_max(max);
    }
}

void XYZSlidersView::setup() {

    for (auto& slider : sliders) {
        add_subview(slider = new LabeledSliderView);
    }

    sliders.x->set_caption("X");
    sliders.y->set_caption("Y");
    sliders.z->set_caption("Z");

    sliders.x->set_slider_color(Color::red);
    sliders.y->set_slider_color(Color::green);
    sliders.z->set_slider_color(Color::blue);

    sliders.x->slider_view->on_value_changed = [&](float value) {
        position.x = value;
        on_change(position);
    };

    sliders.y->slider_view->on_value_changed = [&](float value) {
        position.y = value;
        on_change(position);
    };

    sliders.z->slider_view->on_value_changed = [&](float value) {
        position.z = value;
        on_change(position);
    };
}

void XYZSlidersView::layout() {

    static const float margin = 4;
    const float width = (_frame.size.width - margin * 2) / 3;

    sliders.x->edit_frame() = { width * 0 + margin * 0, 0, width, _frame.size.height };
    sliders.y->edit_frame() = { width * 1 + margin * 1, 0, width, _frame.size.height };
    sliders.z->edit_frame() = { width * 2 + margin * 1, 0, width, _frame.size.height };

}
