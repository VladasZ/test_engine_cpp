//
//  Slider.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 1/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"
#include "RangeConversion.hpp"


namespace ui {

class Slider : public View {

protected:

    float _value = 0.0f;

    View* _slider_view;

public:

    cu::RangeConversion conversion;

    cu::Event<float> on_value_changed;

	using View::View;

	~Slider();

    float value() const;
    void set_value(float);
    void set_converted_value(float);

    void set_slider_color(const gm::Color&);

protected:

    void setup() override;

    void layout() override;

    void _set_slider_position();
};

}
