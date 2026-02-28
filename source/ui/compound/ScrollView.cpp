//
//  ScrollView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "ScrollView.hpp"

using namespace ui;


void ScrollView::setup() {
    init_view(_vertical_slider);

    _conversion.flip = true;

    _vertical_slider->on_value_changed = [&](float value) {
        content_offset.y = -_conversion.convert(value);
    };

    clips = true;
}

void ScrollView::layout() {

    _vertical_slider->edit_frame()  = { 20, _frame.size.height };
    _vertical_slider->place.tr();
    _vertical_slider->edit_frame().origin -= content_offset;

    _conversion.set_target_max(content_size.height - _frame.size.height);

    _vertical_slider->is_hidden = content_size.height < _frame.size.height;

}
