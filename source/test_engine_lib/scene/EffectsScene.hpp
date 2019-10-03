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

class EffectsScene : public scene::Scene {

    scene::Model* cube;

	scene::Model* floor;

    void setup() override;
    void each_frame() override;

};
