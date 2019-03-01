//
//  Window.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include     "Size.hpp"
#include    "Debug.hpp"
#include    "Scene.hpp"
#include "RootView.hpp"

struct GLFWwindow;

class DebugInfoView;

class Screen {

private:

    void _initialize_gl   ();
    void _initialize_ui   ();
    void _initialize_scene();
    void _initialize_image();

    scene::Scene* _scene     = nullptr;
    te::RootView* _root_view = nullptr;

public:
    
    int FPS          = 0;
    int frames_drawn = 0;
    
    Size size              ;
    Size display_resolution;

    Color clear_color;
    
#if DESKTOP_BUILD
    GLFWwindow* glfw_window = nullptr;
#endif

#ifdef DEBUG_VIEW
    DebugInfoView* debug_view = nullptr;
#endif
    
public:

    void initialize(const Size&);
        
    void update();

    void set_size(const Size&);

public:

    void      set_scene(scene::Scene*);
    scene::Scene* scene() const       ;

    te::RootView* root_view() const;

};
