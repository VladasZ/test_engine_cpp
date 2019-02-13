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
#include "Scene.hpp"

struct GLFWwindow;

class DebugInfoView;

namespace te {
class RootView;
}

class Screen {
        
    void on_debug_tick();
    
public:
    
    int FPS = 0;
    int frames_drawn = 0;
    
    Size size;
    Size display_resolution;
    
#if GLFW
    GLFWwindow* glfw_window = nullptr;
#endif

    te::RootView* root_view = nullptr;
    scene::Scene* scene = nullptr;

#ifdef DEBUG_VIEW
    DebugInfoView* debug_view = nullptr;
#endif
    
    void initialize(const Size&);
    
    void setup();
    
    void update();

    void set_size(const Size&);
};
