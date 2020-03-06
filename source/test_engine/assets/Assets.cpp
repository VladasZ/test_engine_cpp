//
//  Assets.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "Assets.hpp"


void Assets::initialize() {
    te::Paths::dump();

    images = new Images();
	shaders = new Shaders();
    buffers = new Buffers();
}
