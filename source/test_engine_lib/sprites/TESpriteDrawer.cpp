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
	sprite->image()->bind();
	auto shader = Assets::shaders->sprite;
	shader->use();
	shader->set_size(sprite->size());
//	Buffers::fullscreen_image->draw();
}
