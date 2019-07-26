//
//  TestEngine.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <functional>

#include "Scene.hpp"
#include "Screen.hpp"

class TestEngine {
public:

    static Screen screen;

    static void start(const gm::Size& window_size = { 1000, 600 });

};
