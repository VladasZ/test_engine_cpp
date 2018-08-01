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
#include "Log.hpp"

static auto touchBeganCondition = [](View* view, const Point &point, int id)
{ return view->containsGlobalPoint(point); };
static auto touchMovedCondition = [](View* view, const Point &point, int id)
{ return view->getTouchID() == id; };
static auto touchEndedCondition = [](View* view, const Point &point, int id)
{ return view->getTouchID() == id; };

TouchEvent Input::onTouchBegan(touchBeganCondition);
TouchEvent Input::onTouchMoved(touchMovedCondition);
TouchEvent Input::onTouchEnded(touchEndedCondition);

#if GLFW

Point Input::cursorPosition;
bool Input::mouseKeyIsPressed;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    
    if (button != GLFW_MOUSE_BUTTON_LEFT) return;
    
    if (action == GLFW_PRESS) {
        Input::mouseKeyIsPressed = true;
        Input::touchBegan(Input::cursorPosition.x, Input::cursorPosition.y, 1);
    }
    else {
        Input::mouseKeyIsPressed = false;
        Input::touchEnded(Input::cursorPosition.x, Input::cursorPosition.y, 1);
    }
}

void cursorPositionCallback(GLFWwindow* window, double x, double y) {
    Input::cursorPosition = Point((float)x, (float)y);
    if (Input::mouseKeyIsPressed) Input::touchMoved((float)x, (float)y, 1);
}

#endif

void Input::initialize() {
#if GLFW
    glfwSetCursorPosCallback(Window::window, cursorPositionCallback);
    glfwSetMouseButtonCallback(Window::window, mouseButtonCallback);
#endif
}

void Input::touchBegan(INPUT_PARAMETERS) {
    onTouchBegan(Point(x, y), id);
}

void Input::touchMoved(INPUT_PARAMETERS) {
    onTouchMoved(Point(x, y), id);
}

void Input::touchEnded(INPUT_PARAMETERS) {
    onTouchEnded(Point(x, y), id);
}

void Input::pressedKey(const char &key) {
    Log(key);
}
