//
//  TESpriteDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "SpritesInclude.hpp"

#ifdef USING_SPRITES

#include "Assets.hpp"
#include "TESpriteDrawer.hpp"


void TESpriteDrawer::draw(sprite::Sprite* sprite) {
    static const float scale = 1.0f;
    Assets::shaders->sprite->use();
    Assets::shaders->sprite->set_size(sprite->size() * scale);
    Assets::shaders->sprite->set_position(sprite->position() * scale);
    Assets::shaders->sprite->set_rotation(sprite->rotation());
    //Assets::shaders->sprite->set_resolution(te::Screen::size);
    sprite->image()->bind();
    Assets::buffers->fullscreen_image->draw();
}

#endif
