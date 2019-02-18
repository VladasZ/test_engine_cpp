//
//  TESceneDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"
#include "SceneDrawer.hpp"

class TESceneDrawer : public scene::SceneDrawer {

    ~TESceneDrawer() override;
    scene::Model::Drawer* init_model_drawer(scene::Model*) override;

};
