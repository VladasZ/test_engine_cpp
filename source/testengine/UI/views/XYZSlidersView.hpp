//
//  XYZSlidersView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "LabeledSliderView.hpp"

class XYZSlidersView : public ui::View {

    ui::LabeledSliderView* _x_slider = nullptr;
    ui::LabeledSliderView* _y_slider = nullptr;
    ui::LabeledSliderView* _z_slider = nullptr;

public:

    using View::View;

    ~XYZSlidersView();

    float multiplier;
    Vector3 position;

    Event<Vector3> on_change;

private:

    void _setup() override;
    void _layout() override;
};

