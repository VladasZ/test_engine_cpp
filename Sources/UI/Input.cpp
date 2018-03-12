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
#include "View.hpp"

static auto touchBeganCondition = [](View *view, Point point) { return view->containsGlobalPoint(point); };
static auto touchMovedCondition = [](View *view, Point point) { return view->getTouchID() != -1; };
static auto touchEndedCondition = [](View *view, Point point) { return view->getTouchID() != -1; };

Input::TouchEvent Input::onTouchBegan(touchBeganCondition);
Input::TouchEvent Input::onTouchMoved(touchMovedCondition);
Input::TouchEvent Input::onTouchEnded(touchEndedCondition);

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
    onTouchBegan(Point(x, y));
}

void Input::touchMoved(INPUT_PARAMETERS) {
    onTouchMoved(Point(x, y));
}

void Input::touchEnded(INPUT_PARAMETERS) {
    onTouchEnded(Point(x, y));
}

void Input::pressedKey(const char &key) {
    Log(key);
}
