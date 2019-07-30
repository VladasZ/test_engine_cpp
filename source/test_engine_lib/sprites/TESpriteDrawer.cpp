//
//  TESpriteDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Assets.hpp"
#include "TESpriteDrawer.hpp"

void TESpriteDrawer::draw(sprites::Sprite* sprite) {
	Assets::shaders->sprite->use();
	Assets::shaders->sprite->set_size(sprite->size);
	Assets::shaders->sprite->set_position(sprite->position);
	sprite->image()->bind();
	Assets::buffers->fullscreen_image->draw();
}
