//
//  RotationTestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 17/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Grid.hpp"
#include "GlobalEvents.hpp"
#include "RotationTestView.hpp"
#include "RotationTestScene.hpp"
#include "PositionManipulator.hpp"

using namespace te;
using namespace gm;
using namespace scene;


void RotationTestScene::_setup() {

    view = new RotationTestView();

    add_object(new Grid());

    auto manip = new PositionManipulator();
    manip->edit_position() = { -10, -10, 0 };
    add_object(manip);

    add_object(vector = new VectorModel());

    Events::screen_did_appear = [&] {
        RotationTestView::sliders->sliders = [&](ui::LabeledSliderView* slider) {
            slider->slider_view->conversion.set_target_min(-gm::math::pi<float>);
            slider->slider_view->conversion.set_target_max( gm::math::pi<float>);
        };
    };

//    RotationTestView::sliders->on_change = [&](Vector3 vec) {
//
//        auto quat_x = Vector4::transform::quaternion_rotating_x(vec.x);
//        auto quat_y = Vector4::transform::quaternion_rotating_y(vec.y);
//        auto quat_z = Vector4::transform::quaternion_rotating_z(vec.z);
//
//        auto result_quat = quat_x * quat_y * quat_z;
//
//        vector->set_rotation(result_quat);
//    };

}
