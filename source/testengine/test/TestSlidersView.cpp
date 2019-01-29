//
//  TestSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestSlidersView.hpp"


void TestSlidersView::_setup() {

    static const float width = 50;

    _x_view = new ui::LabeledSliderView({ 0, 0, width, width });
}
