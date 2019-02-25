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
    scene::Model* monkey_model        = nullptr;
    scene::Model* cube_model          = nullptr;

    scene::Model* floor               = nullptr;

    scene::Model* hor_plane           = nullptr;
    scene::Model* ver_plane           = nullptr;

    scene::Model* line_vector         = nullptr;

    scene::Model* hor_plane_normal_vector = nullptr;
    scene::Model* ver_plane_normal_vector = nullptr;



    void setup() override;
    void each_frame() override;

    Vector3 hor_plane_normal_for_angle(float angle, const Vector3& basestation_orientation);
    Vector3 ver_plane_normal_for_angle(float angle, const Vector3& basestation_orientation);


public:

    void set_vector(const Vector3&);
    void set_x_angle(float);
    void set_y_angle(float);

};
