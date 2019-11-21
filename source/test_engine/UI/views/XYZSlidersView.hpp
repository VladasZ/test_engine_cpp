//
//  XYZSlidersView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/30/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "XYZPack.hpp"
#include "LabeledSliderView.hpp"

class XYZSlidersView : public ui::View {

    cu::XYZPack<ui::LabeledSliderView*> sliders = nullptr;

public:

    using View::View;

    ~XYZSlidersView() override;

    float multiplier = 1.0f;
    gm::Vector3 position;

    Event<gm::Vector3> on_change;

private:

    void _setup() override;
    void _layout() override;
};

