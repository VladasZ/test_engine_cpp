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

#if GLFW

Point Input::cursorPosition;
bool Input::mouseKeyIsPressed;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    
    if (button != GLFW_MOUSE_BUTTON_LEFT) return;
    
    if (action == GLFW_PRESS) {
        Input::mouseKeyIsPressed = true;
        Input::touchBegan(Input::cursorPosition.x, Input::cursorPosition.y);
    }
    else {
        Input::mouseKeyIsPressed = false;
        Input::touchEnded(Input::cursorPosition.x, Input::cursorPosition.y);
    }
}

void cursorPositionCallback(GLFWwindow* window, double x, double y) {
    Input::cursorPosition = Point(x, y);
    if (Input::mouseKeyIsPressed) Input::touchMoved(x, y);
}

#endif

void Input::initialize() {
    
#if GLFW
    glfwSetCursorPosCallback(Window::window, cursorPositionCallback);
    glfwSetMouseButtonCallback(Window::window, mouseButtonCallback);
#else
    //UNIMPLEMENTED;
#endif
}


void Input::touchBegan(INPUT_PARAMETERS) {
    cout << "Began: " << x << " " << y << endl;
}

void Input::touchMoved(INPUT_PARAMETERS) {
    cout << "Moved: " << x << " " << y << endl;
}

void Input::touchEnded(INPUT_PARAMETERS) {
    cout << "Ended: " << x << " " << y << endl;
}

void Input::pressedKey(const char &key) {
    cout << key << endl;
}
