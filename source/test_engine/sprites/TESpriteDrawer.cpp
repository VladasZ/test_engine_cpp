//
//  TESpriteDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "SpritesInclude.hpp"

#ifdef USING_SPRITES

#include "Image.hpp"
#include "Assets.hpp"
#include "GLWrapper.hpp"
#include "TESpriteDrawer.hpp"


void TESpriteDrawer::set_camera_position(const gm::Point& pos) {
    Assets::shaders->textured_sprite->use();
    Assets::shaders->textured_sprite->set_camera_position(pos * GL::render_scale);
    Assets::shaders->sprite->use();
    Assets::shaders->sprite->set_camera_position(pos * GL::render_scale);
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
    shader->set_size(sprite->size() * GL::render_scale);
    shader->set_position(sprite->position() * GL::render_scale);
    shader->set_rotation(sprite->rotation());
    shader->set_selected(sprite->is_selected);

    shader->set_flip(sprite->direction() == gm::Direction::Left);

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
