//
//  SelectionScene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 03/02/20.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Scene.hpp"
#include "BoxModel.hpp"

class SelectionScene : public scene::Scene {

public:

    static inline SelectionScene* instance = nullptr;

private:

    scene::BoxModel* box1 = nullptr;
    scene::BoxModel* box2 = nullptr;

protected:

    void _setup() override;

};
