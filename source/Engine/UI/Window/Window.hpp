//
//  Window.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Point.hpp"
#include "Input.hpp"
#include "Debug.hpp"

class View;
class RootView;
struct GLFWwindow;

#if DEBUG_VIEW
class DebugInfoView;
#endif

class Window {
    
    friend Input;
    
    static void onDebugTick();
    
public:
    
    static int FPS;
    static int framesDrawn;
    
    static TestEngine::Size size;
    
    static RootView *rootView;

#if GLFW
    static GLFWwindow *window;
#endif
    
#if DEBUG_VIEW
    static DebugInfoView *debugInfoView;
#endif
    
    static void initialize(int width, int height);
    
    static void setup();
    
    static void update();
    
    static void sizeChanged(GLFWwindow* window, int width, int height);
};
