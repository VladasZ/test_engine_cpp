//
//  Slider.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 1/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Touch.hpp"
#include "GmMath.hpp"
#include "Slider.hpp"
#include "ImageButton.hpp"

using namespace ui;
using namespace gm;


Slider::~Slider() {
	//TODO: -
}

float Slider::value() const {
    return conversion.convert(_value);
}

void Slider::set_value(float value) {
    _value = value;
    gm::math::clamp(_value);
    on_value_changed(this->value());
    _set_needs_layout();
}

void Slider::set_converted_value(float value) {
    _value = conversion.convert_back(value);
    gm::math::clamp(_value);
    on_value_changed(this->value());
	_set_needs_layout();
}

void Slider::set_slider_color(const Color& color) {
    _slider_view->background_color = color;
}

void Slider::setup() {
	init_view(_slider_view);

	set_slider_color(Color::green);

    enable_touch();
    on_touch = [this](Touch* touch) {
        if (touch->is_ended()) {
            return;
        }
        set_value(1.0f - touch->position.y / _frame.size.height);
    };
}

static const float buttons_size = 28;

void Slider::layout() {
    _set_slider_position();
}

void Slider::_set_slider_position() {
    _slider_view->edit_frame() =
            { 0,
              (_frame.size.height - buttons_size / 4) * (1 - _value),
              _frame.size.width,
			  buttons_size / 4
            };
}
