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
#include "OldView.hpp"
#include "Log.hpp"
#include "GlobalEvents.hpp"
#include "Dictionary.hpp"


#if GLFW

ui::Point Input::cursorPosition;
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
    Input::cursorPosition = ui::Point((float)x, (float)y);
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
	ui::Point location{ x, y };
	Events::touch(location);

	for (auto view : _subscribedViews)
		if (view->contains_global_point(location)) {
			view->_touch_id = id;
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Began));
			break;
		}
}

void Input::touchMoved(INPUT_PARAMETERS) {
	ui::Point location{ x, y };
	Events::touch(location);
	
	for (auto view : _subscribedViews)
		if (id == view->_touch_id) {
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Moved));
			break;
		}
}

void Input::touchEnded(INPUT_PARAMETERS) {
	ui::Point location{ x, y };
	Events::touch(location);

	for (auto view : _subscribedViews)
		if (id == view->_touch_id) {
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Ended));
			view->_touch_id = -1;
			break;
		}
}

void Input::pressedKey(const char &key) {
    Log(key);
}

void Input::subscribeView(OldView* view) {
	_subscribedViews.push_back(view);
}

void Input::unsubscribeView(OldView* view) {
	_subscribedViews.remove(view);
}
