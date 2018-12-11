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

class OldView;
class Scene;
class Input;
class RootView;
class FrameBuffer;
struct GLFWwindow;

#if DEBUG_VIEW
class DebugInfoView;
#endif

class Window {
    
    friend Input;
    
    static void on_debug_tick();
    
public:
    
    static inline int FPS = 0;
    static inline int frames_drawn = 0;
    
    static inline ui::Size size;
    static inline ui::Size screen_resolution;
    
    static inline RootView* root_view = nullptr;
    static inline FrameBuffer* root_frame_buffer = nullptr;

	static inline Scene* current_scene = nullptr;

#if GLFW
    static inline GLFWwindow* window = nullptr;
#endif
    
    static void initialize(int width, int height);
    
    static void setup();
    
    static void update();

	static void set_scene(Scene* scene);
    
    static void size_changed(GLFWwindow* window, int width, int height);
};
