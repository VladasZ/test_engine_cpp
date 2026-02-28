//
//  SceneConfig.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "SceneDrawer.hpp"

namespace scene::config {
	void set_drawer(SceneDrawer*);
	SceneDrawer* drawer();
}
