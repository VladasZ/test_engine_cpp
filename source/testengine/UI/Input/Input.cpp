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

ui::Point Input::cursor_position;
bool Input::mouse_key_is_pressed;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    
    if (button != GLFW_MOUSE_BUTTON_LEFT) 
		return;
    
    if (action == GLFW_PRESS) {
        Input::mouse_key_is_pressed = true;
        Input::touch_began(Input::cursor_position.x, Input::cursor_position.y, 1);
    }
    else {
        Input::mouse_key_is_pressed = false;
        Input::touch_ended(Input::cursor_position.x, Input::cursor_position.y, 1);
    }
}

void cursor_position_callback(GLFWwindow* window, double x, double y) {
	Input::cursor_position = { static_cast<float>(x), static_cast<float>(y) };
	Events::cursor_moved(Input::cursor_position);
    if (Input::mouse_key_is_pressed) 
		Input::touch_moved(static_cast<float>(x), static_cast<float>(y), 1);
}

#endif

void Input::initialize() {
#if GLFW
    glfwSetCursorPosCallback(Window::window, cursor_position_callback);
    glfwSetMouseButtonCallback(Window::window, mouse_button_callback);
#endif
}

void Input::touch_began(INPUT_PARAMETERS) {
	ui::Point location { x, y };
	Events::touch(location);

	for (auto view : _subscribed_views) {
		if (view->contains_global_point(location)) {
			view->_touch_id = id;
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Began));
			break;
		}
	}
}

void Input::touch_moved(INPUT_PARAMETERS) {
	ui::Point location { x, y };
	Events::touch(location);
	
	for (auto view : _subscribed_views) {
		if (id == view->_touch_id) {
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Moved));
			break;
		}
	}
}

void Input::touch_ended(INPUT_PARAMETERS) {
	ui::Point location{ x, y };
	Events::touch(location);

	for (auto view : _subscribed_views) {
		if (id == view->_touch_id) {
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Ended));
			view->_touch_id = -1;
			break;
		}
	}
}

void Input::pressed_key(char key) {
    Log(key);
}

void Input::subscribe_view(OldView* view) {
	_subscribed_views.push_back(view);
}

void Input::unsubscribe_view(OldView* view) {
	_subscribed_views.remove(view);
}
