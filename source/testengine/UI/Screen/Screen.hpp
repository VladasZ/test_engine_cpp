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

#if DEBUG_VIEW
class DebugInfoView;
#endif

class Screen {
        
    static void on_debug_tick();
    
public:
    
    static inline int FPS = 0;
    static inline int frames_drawn = 0;
    
    static inline ui::Size size;
    static inline ui::Size display_resolution;
    
#if GLFW
    static inline GLFWwindow* glfw_window = nullptr;
#endif
    
    static void initialize(int width, int height);
    
    static void setup();
    
    static void update();

};
