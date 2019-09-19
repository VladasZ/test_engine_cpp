//
//  TestLevel.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <test/DebugInfoView.hpp>
#include "Box2D/Box2D.h"

#include "Log.hpp"
#include "Screen.hpp"
#include "Assets.hpp"
#include "TestLevel.hpp"

float world_width = 100.0f;


using namespace sprites;

TestLevel::TestLevel() {

    box = new DynamicBody(Assets::images->palm, { 2, 2 }, { 3, 10 });
    add_sprite(box);

    floor = new Platform(Assets::images->square, { 20, 1 }, { 10, 2 });
    add_sprite(floor);


}

void TestLevel::update() {
    Level::update();
    te::Screen::debug_view->info_label->set_text(box->position().to_string());
}
