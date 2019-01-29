//
//  TestSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestSlidersView.hpp"

TestSlidersView TestSlidersView::view = TestSlidersView({ 0, 0, 400, 400 });

void TestSlidersView::_setup() {

    static const float width  = 50;
    static const float height = 300;
    static const float margin = 10;

    _x_view = new ui::LabeledSliderView({ width * 0 + margin * 0, 0, width, height });
    _y_view = new ui::LabeledSliderView({ width * 1 + margin * 1, 0, width, height });
    _z_view = new ui::LabeledSliderView({ width * 2 + margin * 2, 0, width, height });

    add_subview(_x_view);
    add_subview(_y_view);
    add_subview(_z_view);

    _x_view->set_caption("X");
    _y_view->set_caption("Y");
    _z_view->set_caption("Z");
}
