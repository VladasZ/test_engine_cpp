//
//  SceneDrawer.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

namespace scene {

class SceneDrawer {

public:

    virtual ~SceneDrawer();
    virtual Model::Drawer* init_model_drawer(Model*) = 0;

};

}
