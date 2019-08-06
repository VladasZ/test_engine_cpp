//
//  TestLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Walker.hpp"
#include "Assets.hpp"
#include "TestLevel.hpp"

using namespace sprites;

TestLevel::TestLevel() {
	auto sprite = new Walker(Assets::images->cat);
	sprite->position = { 100, 100 };
    sprite->velocity = { 5, 15 };
    add_sprite(sprite);
}
