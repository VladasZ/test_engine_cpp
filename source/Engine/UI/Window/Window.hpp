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
class FrameBuffer;
struct GLFWwindow;

#if DEBUG_VIEW
class DebugInfoView;
#endif

class Window {
    
    friend Input;
    
    static void onDebugTick();
    
public:
    
    static inline int FPS = 0;
    static inline int framesDrawn = 0;
    
    static inline TestEngine::Size size;
    static inline TestEngine::Size screenResolution;
    
    static inline RootView* rootView;
    static inline FrameBuffer* rootFrameBuffer;

#if GLFW
    static inline GLFWwindow* window;
#endif
    
    static void initialize(int width, int height);
    
    static void setup();
    
    static void update();
    
    static void sizeChanged(GLFWwindow* window, int width, int height);

    static void resetViewport();
};
