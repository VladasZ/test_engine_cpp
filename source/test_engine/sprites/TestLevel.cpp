//
//  TestLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestLevel.hpp"

#ifdef USING_SPRITES

#include "Screen.hpp"
#include "Assets.hpp"

using namespace te;
using namespace gm;
using namespace sprite;


TestLevel::TestLevel() {

    //set_gravity(0);

    box = new DynamicBody({ 0, 0 }, { 5, 10 });
    box->set_image(Assets::images->scale_test);
    add_sprite(box);
    box->add_rotation(0.1f);

    for (int i = 0; i < 200; i++) {
        add_sprite(new DynamicBody({ 0, i }, { 1, 2 }));
        _sprites.back()->color = gm::Color::random();
    }
    
    add_sprite(new DynamicBody({ 10, 0 }, { 10, 20 }));
    _sprites.back()->set_image(Assets::images->scale_test);
    _sprites.back()->add_rotation(-0.1f);

    add_sprite(new DynamicBody({ -10, 0 }, { 2.5, 5.0 }));
    _sprites.back()->set_image(Assets::images->scale_test);
    _sprites.back()->add_rotation(-0.1f);


	floor = new Body(gm::Point { 0, -20 }, gm::Size { 100.0f, 1 });
    floor->set_image(Assets::images->square);
	add_sprite(floor);

    right = new Body(gm::Point { 40, -20 }, gm::Size { 1, 100.0 });
    right->set_image(Assets::images->square);
    add_sprite(right);

    left = new Body(gm::Point { -40, -20 }, gm::Size { 1, 100.0 });
    left->set_image(Assets::images->square);
    add_sprite(left);

    unit = new Unit({ 0, 0 }, { 17.0 / 4.0, 28.0 / 4.0 });
    unit->set_image(Assets::images->frisk);
    add_sprite(unit);
    unit->fix_rotation(true);
}

void TestLevel::setup() {

}

#endif
