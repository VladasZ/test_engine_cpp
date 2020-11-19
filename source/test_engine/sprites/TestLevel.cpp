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

    //set_gravity(0);

    box = new DynamicBody(Assets::images->scale_test, { 0, 0 }, { 5, 10 });
    add_sprite(box);
    box->add_rotation(0.1f);

    for (int i = 0; i < 100; i++) {
        add_sprite(new DynamicBody(Assets::images->scale_test, { 0, i }, { 1, 2 }));
    }
    
    add_sprite(new DynamicBody(Assets::images->scale_test, { 10, 0 }, { 10, 20 }));
    _sprites.back()->add_rotation(-0.1f);

    add_sprite(new DynamicBody(Assets::images->scale_test, { -10, 0 }, { 2.5, 5.0 }));
    _sprites.back()->add_rotation(-0.1f);


	floor = new Platform(Assets::images->square, gm::Point { 0, -20 }, gm::Size { 100.0f, 1 });
	add_sprite(floor);

    right = new Platform(Assets::images->square, gm::Point { 40, -20 }, gm::Size { 1, 100.0 });
    add_sprite(right);

    left = new Platform(Assets::images->square, gm::Point { -40, -20 }, gm::Size { 1, 100.0 });
    add_sprite(left);

}

void TestLevel::update() {
    Level::update();
}
