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

//void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//    Window::onKeyPressed(key);
//}

void characterCallback(GLFWwindow* window, unsigned int codepoint) {
    Input::pressedKey(codepoint);
}

void Input::initialize() {
    
#if GLFW
    
    //glfwSetKeyCallback(Window::window, keyCallback);
    glfwSetCharCallback(Window::window, characterCallback);
    
#else
    //UNIMPLEMENTED;
#endif
}


void Input::touchBegan(INPUT_PARAMETERS) {
    
}

void Input::touchMoved(INPUT_PARAMETERS) {
    
}

void Input::touchEnded(INPUT_PARAMETERS) {
    
}

void Input::pressedKey(const char &key) {
    cout << key << endl;
}
