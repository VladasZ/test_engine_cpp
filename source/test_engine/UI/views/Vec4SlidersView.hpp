//
//  Vec4SlidersView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/18/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector4.hpp"
#include "LabeledSliderView.hpp"

class Vec4SlidersView : public ui::View {

    ui::LabeledSliderView* _x_slider = nullptr;
    ui::LabeledSliderView* _y_slider = nullptr;
    ui::LabeledSliderView* _z_slider = nullptr;
    ui::LabeledSliderView* _w_slider = nullptr;

public:

    using View::View;

    ~Vec4SlidersView() override;

    float multiplier = 1.0f;
    gm::Vector4 position;

    cu::Event<gm::Vector4> on_change;

private:

    void _setup() override;
    void _layout() override;
};

