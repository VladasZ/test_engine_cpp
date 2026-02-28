//
//  SceneConfig.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "SceneConfig.hpp"

using namespace scene;
using namespace config;

static SceneDrawer* _drawer = nullptr;

void config::set_drawer(SceneDrawer* drawer) {
#ifdef DEBUG
	if (_drawer != nullptr) {
        Fatal("Scene drawer must be set only once");
    }
	if (drawer == nullptr) {
        Fatal("Scene drawer must be nonnull");
    }
#endif
	_drawer = drawer;
}

SceneDrawer* config::drawer() {
#ifdef DEBUG
	if (_drawer == nullptr) {
        Fatal("Scene drawer is not set before first usage");
    }
#endif
	return _drawer;
}
