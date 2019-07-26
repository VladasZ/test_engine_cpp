
//
//  TestEngine.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/13/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "Mouse.hpp"
#include "Camera.hpp"
#include "Keyboard.hpp"
#include "GLWrapper.hpp"
#include "TestEngine.hpp"
#include "GlobalEvents.hpp"

using namespace gm;

Screen TestEngine::screen;

#include "Log.hpp"
#include "Paths.hpp"

using namespace te;

void TestEngine::start(const Size& window_size) {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    screen.initialize(window_size);
}

#ifdef DESKTOP_BUILD

//void TestEngine::start_main_loop() {
//	start();
//    GL::start_main_loop([&]{
//        screen.update();
//    });
//}

#endif
