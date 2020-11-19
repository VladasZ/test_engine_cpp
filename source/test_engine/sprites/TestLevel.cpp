//
//  TestLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//


#include "Screen.hpp"
#include "Assets.hpp"
#include "TestLevel.hpp"

using namespace te;
using namespace sprite;


TestLevel::TestLevel() {

    set_gravity(0);

    box = new DynamicBody(Assets::images->scale_test, { 0, 0 }, { 5, 10 });
    add_sprite(box);
    box->add_rotation(0.1f);


    add_sprite(new DynamicBody(Assets::images->scale_test, { 20, 0 }, { 10, 20 }));
    _sprites.back()->add_rotation(-0.1f);

    add_sprite(new DynamicBody(Assets::images->scale_test, { -20, 0 }, { 2.5f, 5.0f }));
    _sprites.back()->add_rotation(-0.1f);


	/*floor = new Platform(Assets::images->square, gm::Size { 20.0f, 0.1f }, gm::Point { 10, 2 });
	add_sprite(floor);*/

}

void TestLevel::update() {
    Level::update();
}
