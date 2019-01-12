//
//  Window.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Debug.hpp"

struct GLFWwindow;

class DebugInfoView;

namespace te {
class RootView;
}

class Screen {
        
    static void on_debug_tick();
    
public:
    
    static inline int FPS = 0;
    static inline int frames_drawn = 0;
    
    static inline Size size;
    static inline Size display_resolution;
    
#if GLFW
    static inline GLFWwindow* glfw_window = nullptr;
#endif

    static inline te::RootView* root_view = nullptr;

    static inline DebugInfoView* debug_view = nullptr;
    
    static void initialize(const Size& size);
    
    static void setup();
    
    static void update();

    static void set_size(const Size& size);
};
