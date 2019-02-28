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

    scene::Model* cube;
    scene::Model* plane;

    void setup() override;
    void each_frame() override;

    void set_vector(const Vector3&);
};
