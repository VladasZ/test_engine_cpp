//
//  TestSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestSlidersView.hpp"

static const float width  = 400;
static const float height = 280;
static const float margin = 5;

TestSlidersView TestSlidersView::view = TestSlidersView({ 0, 0, width, height });

void TestSlidersView::_setup() {

    _box_position_view = new XYZSlidersView({ 0, 0, 168, height });
    add_subview(_box_position_view);

    _fov_view = new ui::LabeledSliderView({ _box_position_view->frame().max_x() + margin, 0, 50, height });
    add_subview(_fov_view);
    _fov_view->slider_view->multiplier = 0.3f;
    _fov_view->set_caption("fV");

    _z_near_view = new ui::LabeledSliderView({ _fov_view->frame().max_x() + margin, 0, 50, height });
    add_subview(_z_near_view);
    _z_near_view->set_caption("nN");
    _z_near_view->slider_view->multiplier = 0.2f;

    _z_far_view = new ui::LabeledSliderView({ _z_near_view->frame().max_x() + margin, 0, 50, height });
    add_subview(_z_far_view);
    _z_far_view->set_caption("zF");
    _z_far_view->slider_view->multiplier = 200.0f;

    _box_rotation_view = new XYZSlidersView({ _z_far_view->frame().max_x() + margin * 4, 0, 168, height });
    add_subview(_box_rotation_view);

    _box_angle_view = new ui::LabeledSliderView({ _box_rotation_view->frame().max_x(), 0, 50, height });
    add_subview(_box_angle_view);
    _box_angle_view->set_caption("an");
    _box_angle_view->slider_view->multiplier = 3.14159265358f * 2;

}
