//
//  PhysicsScene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Scene.hpp"
#include "Model.hpp"
#include "BoxModel.hpp"

class PhysicsScene : public scene::Scene {

private:

    scene::BoxModel* ground = nullptr;
    scene::Model* ball = nullptr;


protected:

    void _setup() override;

};
