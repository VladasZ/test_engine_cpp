//
//  TestScreen.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 25/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#include "TestView.hpp"
#include "WorldScene.hpp"
#include "TestScreen.hpp"
#include "PhysicsScene.hpp"

using namespace te;


TestScreen::TestScreen() : Screen({ 1000, 800 }) {
    clear_color = gm::Color::gray;
    set_view(new TestView);
    set_scene(new PhysicsScene);
}
