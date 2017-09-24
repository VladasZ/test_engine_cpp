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
#include "Types.h"
#include "Platform.h"
#include "Input.hpp"

class View;
struct GLFWwindow;

class Window {
    
    friend Input;
    
    static View *rootView;
    
    static void touchBegan(const TestEngine::Point &position);
    static void touchMoved(const TestEngine::Point &position);
    
public:
    
    static TestEngine::Size size;
    
#ifndef IOS
    static GLFWwindow *window;
#endif
    
    static void initialize(int width = 1000, int height = 1000);
    
    static void setup();
    
    static void update();
        
    static void didTouch(const int &x, const int &y);
    
    static void sizeChanged(GLFWwindow* window, int width, int height);
};
