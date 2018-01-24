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

class View;
struct GLFWwindow;

class Window MEMORY_MANAGED(Window) {
    
    friend Input;
    
    static int FPS;
    static int framesDrawn;
    
    static void touchBegan(const TestEngine::Point &position);
    static void touchMoved(const TestEngine::Point &position);
    
    static void on30FramesDrawn();
    
public:
    
    static TestEngine::Size size;
    
    static View *rootView;

#if GLFW
    static GLFWwindow *window;
#endif
    
    static void initialize(int width, int height);
    
    static void setup();
    
    static void update();
        
    static void didTouch(const int &x, const int &y);
    
    static void sizeChanged(GLFWwindow* window, int width, int height);
    
    static void onCharacterInput(const char &ch);
    static void onKeyPressed(const int &key);
};
