//
//  RotationTestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 17/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "RotationTestView.hpp"

using namespace te;

void RotationTestView::_setup() {
    add_subview(sliders = new XYZSlidersView);
    sliders->edit_frame() = { 180, 280 };
}

void RotationTestView::_layout() {
    _calculate_absolute_frame();

    _layout_subviews();
}

