//
//  Input.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "Point.hpp"
#include "Window.hpp"
#include "GL.hpp"
#include "STL.hpp"
#include "Platform.h"
#include "Log.hpp"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    cout << key << endl;
    cout << (char)key << endl;
}

void characterCallback(GLFWwindow* window, unsigned int codepoint) {
    Window::onCharacterInput(codepoint);
}

void Input::initialize() {
    
#if GLFW
    
    //glfwSetKeyCallback(Window::window, keyCallback);
    glfwSetCharCallback(Window::window, characterCallback);
    
#else
    UNIMPLEMENTED;
#endif
}


void Input::touchBegan(double x, double y) {
    
    Window::touchBegan(Point(x, y));
}

void Input::touchMoved(double x, double y) {
    
    Window::touchMoved(Point(x, y));
}

void Input::touchEnded(double x, double y) {
    
}
