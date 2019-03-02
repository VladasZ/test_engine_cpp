//
//  Shaders.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include                "Rect.hpp"
#include              "Assets.hpp"
#include             "Buffers.hpp"
#include          "BufferData.hpp"
#include "BufferConfiguration.hpp"

#include "OpenGLHeaders.hpp"

static const Rect fulscreen_rect = { -1, -1, 2, 2 };

Buffers::Buffers() {
    fullscreen = new gl::Buffer(gl::BufferData::from_rect(fulscreen_rect), gl::BufferConfiguration::_2, Assets::shaders->ui);
    fullscreen->draw_mode = GL_TRIANGLE_STRIP;
}
