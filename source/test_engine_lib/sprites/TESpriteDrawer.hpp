//
//  TESpriteDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/25/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#ifndef NO_BOX2D

#pragma once

#include "SpriteDrawer.hpp"

class TESpriteDrawer : public sprites::SpriteDrawer {
	void draw(sprites::Sprite* sprite) override;
};

#endif
