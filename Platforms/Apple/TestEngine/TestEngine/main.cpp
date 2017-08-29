//
//  main.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#define GLEW_STATIC

#include "TestEngine.h"

int main() {
    
    Window::initialize();
    
    do {
        Window::update();
        
        glfwSwapBuffers(Window::window);
        glfwPollEvents();
    }
    while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
           glfwWindowShouldClose(Window::window) == 0);
    
    return 0;
}
