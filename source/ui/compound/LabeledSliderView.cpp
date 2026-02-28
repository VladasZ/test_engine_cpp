//
//  LabeledSliderView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 1/29/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "Font.hpp"
#include "Button.hpp"
#include "LabeledSliderView.hpp"

using namespace ui;


void LabeledSliderView::set_caption(const std::string& caption) {
    _caption_label->set_text(caption);
}

void LabeledSliderView::set_slider_color(const gm::Color& color) {
    slider_view->set_slider_color(color);
}

void LabeledSliderView::setup() {
    _caption_label = new Label();
    _value_label   = new Label();
    _reset_button  = new Button();
    slider_view    = new Slider();

    _value_label->set_text("0.00");

    slider_view->on_value_changed = [&](float value) {
        _value_label->set_text(std::to_string(value).substr(0, 4));
    };

    _reset_button->on_press = [&] {
        slider_view->set_value(0.5f);
    };

    add_subview(_caption_label);
    add_subview(_value_label);
    add_subview(_reset_button);
    add_subview(slider_view);
}

static const float label_height = 28.0f;

void LabeledSliderView::layout() {

    _value_label->edit_frame() =
            { 0,
              0,
              _frame.size.width,
              label_height,
            };

    slider_view->edit_frame() =
            { 0,
              label_height,
			  _frame.size.width,
              _frame.size.height - label_height * 2
            };

    _caption_label->edit_frame() =
            { 0,
              _frame.size.height - label_height,
              _frame.size.width,
              label_height
            };

    _reset_button->edit_frame() = _caption_label->frame();

}
