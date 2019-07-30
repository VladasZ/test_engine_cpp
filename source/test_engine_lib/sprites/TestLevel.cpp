//
//  TestLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Assets.hpp"
#include "TestLevel.hpp"

using namespace sprites;

TestLevel::TestLevel() {
	auto sprite = new Sprite(Assets::images->cat);
	sprite->set_position({ 100, 100 });
	sprite->set_velocity({ 0.2, 0.1 });
	add_sprite(sprite);
}
