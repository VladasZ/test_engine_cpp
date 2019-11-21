//
//  Buffers.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Buffer.hpp"

struct Buffers {

    gl::Buffer* fullscreen;
    gl::Buffer* fullscreen_image;
    gl::Buffer* fullscreen_outline;

    Buffers();
};
