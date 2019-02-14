//
//  TestEngine.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <functional>

#include "Screen.hpp"

class TestEngine {
public:

    static Screen screen;

    static void initialize(const Size& window_size);
    static void start_main_loop(std::function<void()> on_frame_drawn);
};
