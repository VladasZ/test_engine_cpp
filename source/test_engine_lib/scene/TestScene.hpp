//
//  TestScene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Scene.hpp"
#include "Model.hpp"

class TestScene : public scene::Scene {

    scene::Model* up                  = nullptr;
    scene::Model* side                = nullptr;

    scene::Model* indicator           = nullptr;
    scene::Model* direction_vector    = nullptr;
    scene::Model* plane_normal_vector = nullptr;
    scene::Model* up_vector           = nullptr;
    scene::Model* monkey_model        = nullptr;
    scene::Model* cube_model          = nullptr;

    scene::Model* floor               = nullptr;

    void setup() override;
    void each_frame() override;

    Vector3 horizontal_plane_normal_for_angle(float angle, const Vector3& basestation_orientation);


public:

    void set_vector(const Vector4&);

};
