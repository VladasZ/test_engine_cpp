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


void TESpriteDrawer::set_camera_position(const gm::Point& pos) {
    Assets::shaders->textured_sprite->use();
    Assets::shaders->textured_sprite->set_camera_position(pos);
    Assets::shaders->sprite->use();
    Assets::shaders->sprite->set_camera_position(pos);
}

void TESpriteDrawer::draw(sprite::Sprite* sprite) {

    gl::Shader* shader = nullptr;

    if (sprite->has_image()) {
        shader = Assets::shaders->textured_sprite;
    }
    else {
        shader = Assets::shaders->sprite;
    }

    shader->use();
    shader->set_size(sprite->size());
    shader->set_position(sprite->position());
    shader->set_rotation(sprite->rotation());

    if (sprite->has_image()) {
        sprite->image()->bind();
        Assets::buffers->fullscreen_image->draw();
    }
    else {
        shader->set_color(sprite->color);
        Assets::buffers->fullscreen->draw();
    }

}

#endif
