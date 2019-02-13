//
//  TESceneDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TESceneDrawer.hpp"
#include "TEModelDrawer.hpp"

TESceneDrawer::~TESceneDrawer() { }

scene::Model::Drawer* TESceneDrawer::init_model_drawer(scene::Model* model) {
    return new TEModelDrawer(model);
}
