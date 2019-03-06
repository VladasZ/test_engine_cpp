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

using namespace gm;

static const Rect fulscreen_rect = { -1, -1, 2, 2 };

Buffers::Buffers() {
    fullscreen = new gl::Buffer(gl::BufferData::from_rect(fulscreen_rect), gl::BufferConfiguration::_2, Assets::shaders->ui);
    fullscreen->draw_mode = 0x0005;

    fullscreen_image = new gl::Buffer(gl::BufferData::from_rect_to_image(fulscreen_rect), gl::BufferConfiguration::_2_2, Assets::shaders->ui_texture);
    fullscreen_image->draw_mode = 0x0005;
}
