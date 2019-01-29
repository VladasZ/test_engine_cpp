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

    static const float width = 50;
    static const float height = 300;

    _x_view = new ui::LabeledSliderView({ 0, width * 0, width, height });
    _y_view = new ui::LabeledSliderView({ 0, width * 1, width, height });
    _z_view = new ui::LabeledSliderView({ 0, width * 2, width, height });

    _x_view->set_caption("X");
    _y_view->set_caption("Y");
    _z_view->set_caption("Z");

    add_subview(_x_view);
    add_subview(_y_view);
    add_subview(_z_view);
}
