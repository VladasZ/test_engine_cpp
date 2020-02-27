//
//  Assets.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Assets.hpp"

void Assets::initialize() {
    images = new Images();
	shaders = new Shaders();
    buffers = new Buffers();
}
