//
//  TestLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#ifndef NO_BOX2D

#include "Log.hpp"
#include "Screen.hpp"
#include "Assets.hpp"
#include "TestLevel.hpp"
#include "DebugInfoView.hpp"

static float world_width = 100.0f;

using namespace sprites;

TestLevel::TestLevel() {

    box = new DynamicBody(Assets::images->scale_test, { 1, 2 }, { 3, 10 });
    add_sprite(box);

    box->add_rotation(0.1);

//	box2 = new DynamicBody(Assets::images->palm, { 2, 2 }, { 4, 15 });
//	add_sprite(box2);

//	for (unsigned i = 0; i < 5; i++) {
//		add_sprite(new DynamicBody(Assets::images->palm, { 5, 1 }, gm::Point { 4.0f + (float)i * 0.05f, 15.0f }));
//	}
//
//	for (unsigned i = 0; i < 50; i++) {
//		add_sprite(new DynamicBody(Assets::images->palm, { 0.5, 0.5 }, gm::Point{ 4.0f + (float)i * 0.05f, 15.0f }));
//	}
//
//
//    floor = new Platform(Assets::images->square, gm::Size { 20.0f, 0.1f }, gm::Point { 10, 2 });
//    add_sprite(floor);
//
//	add_sprite(new Platform(Assets::images->square, { 0.1f, 20.0f }, { 20, 5 }));
//	add_sprite(new Platform(Assets::images->square, { 0.1f, 20.0f }, {  0, 5 }));

}

void TestLevel::update() {
    Level::update();
#ifdef DEBUG
   // te::Screen::debug_view->info_label->set_text(box->position().to_string());
#endif
}

#endif
