//
//  TESpriteDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "SpritesInclude.hpp"

#ifdef USING_SPRITES

#include "SpriteDrawer.hpp"


class TESpriteDrawer : public sprite::SpriteDrawer {
	void draw(sprite::Sprite* sprite) override;
};

#endif
