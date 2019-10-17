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
#include "XYZPack.hpp"
#include "PointLight.hpp"

class TestScene : public scene::Scene {

    scene::PointLight* light;

    scene::Model* cube;
#ifndef NO_ASSIMP
    scene::Model* monkey;
#endif

	cu::XYZPack<scene::Model*> walls;

    void setup() override;
    void each_frame() override;

    void set_vector(const gm::Vector3&);
};
