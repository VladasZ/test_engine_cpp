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
        RotationTestView::sliders->sliders.z->slider_view->conversion.converted_minimum = -gm::math::pi<float>;
        RotationTestView::sliders->sliders.z->slider_view->conversion.converted_maximum =  gm::math::pi<float>;

    };


    RotationTestView::sliders->on_change = [&](Vector3 vec) {

        Vector4 vec4 = vec;
        Logvar(vec);
        Logvar(vec4);
        vec4.normalize();
        Logvar(vec4);
        auto quat = Vector4::transform::quaternion_rotating_y(vec.z);
        Logvar(quat);
        Logvar(vec.z);
        Logvar(quat.length());
        Separator;


        vector->set_rotation(quat);
    };

}
