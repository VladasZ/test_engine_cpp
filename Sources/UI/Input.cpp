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
#include "DebugInfoView.hpp"
#include "GL.hpp"

vector<Button *> Input::buttons;

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
#endif
}

void Input::touchBegan(INPUT_PARAMETERS) {
    
    Point point(x, y);
    
    for (auto button : buttons) {
        if (button->frame.contains(point)) {
            button->action();
            return;
        }
    }
    
    String text = "Touch began: " + to_string(x) + " " + to_string(y);
    DebugInfoView::instance->setTouchLabelText(text);
}

void Input::touchMoved(INPUT_PARAMETERS) {
    String text = "Touch moved: " + to_string(x) + " " + to_string(y);
    DebugInfoView::instance->setTouchLabelText(text);
}

void Input::touchEnded(INPUT_PARAMETERS) {
    String text = "Touch ended: " + to_string(x) + " " + to_string(y);
    DebugInfoView::instance->setTouchLabelText(text);
}

void Input::pressedKey(const char &key) {
    Log(key);
}
