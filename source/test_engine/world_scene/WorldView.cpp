//
//  WorldView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "WorldView.hpp"
#include "RangeConversion.hpp"

using namespace cu;
using namespace ui;
using namespace te;


RangeConversion conv;

void WorldView::_setup() {
    init_view(testView, { 300, 300 });
    init_view(sliders,  { 200, 400 });

    testView->clips = true;

    conv.converted_minimum = -500;
    conv.converted_maximum = 500;


    sliders->sliders.x->slider_view->on_value_changed = [&](float value) {
        auto co = conv.convert(value);
        Log(co);
        testView->content_offset.x = co;
    };

    sliders->sliders.y->slider_view->on_value_changed = [&](float value) {
        auto co = conv.convert(value);
        Log(co);
        testView->content_offset.y = co;
    };

}

void WorldView::_layout() {
    _calculate_absolute_frame();
    testView->place_at_center();
    _layout_subviews();
}
