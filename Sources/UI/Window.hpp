//
//  Window.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Types.h"

struct GLFWwindow;

class Window {
    
public:
    
    static Size size;
    static GLFWwindow *window;
    
    static void initialize(int width = 1000, int height = 1000);
    
    static Float pixelToGLX(Float x);
    static Float pixelToGLY(Float y);
    static Float pixelFromGLX(Float x);
    static Float pixelFromGLY(Float y);
};
