//
//  Input.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "OldInput.hpp"
#include "Point.hpp"
#include "Window.hpp"
#include "DebugInfoView.hpp"
#include "GL.hpp"
#include "OldView.hpp"
#include "Log.hpp"
#include "GlobalEvents.hpp"
#include "Dictionary.hpp"


#if GLFW

ui::Point OldInput::cursor_position;
bool OldInput::mouse_key_is_pressed;

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    
    if (button != GLFW_MOUSE_BUTTON_LEFT) 
		return;
    
    if (action == GLFW_PRESS) {
        OldInput::mouse_key_is_pressed = true;
        OldInput::touch_began(OldInput::cursor_position.x, OldInput::cursor_position.y, 1);
    }
    else {
        OldInput::mouse_key_is_pressed = false;
        OldInput::touch_ended(OldInput::cursor_position.x, OldInput::cursor_position.y, 1);
    }
}

void cursor_position_callback(GLFWwindow* window, double x, double y) {
	OldInput::cursor_position = { static_cast<float>(x), static_cast<float>(y) };
	Events::cursor_moved(OldInput::cursor_position);
    if (OldInput::mouse_key_is_pressed) 
		OldInput::touch_moved(static_cast<float>(x), static_cast<float>(y), 1);
}

#endif

void OldInput::initialize() {
#if GLFW
    glfwSetCursorPosCallback(Window::window, cursor_position_callback);
    glfwSetMouseButtonCallback(Window::window, mouse_button_callback);
#endif
}

void OldInput::touch_began(INPUT_PARAMETERS) {
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

void OldInput::touch_moved(INPUT_PARAMETERS) {
	ui::Point location { x, y };
	Events::touch(location);
	
	for (auto view : _subscribed_views) {
		if (id == view->_touch_id) {
			view->_on_touch(Touch(view->local_point_from(location), Touch::Event::Moved));
			break;
		}
	}
}

void OldInput::touch_ended(INPUT_PARAMETERS) {
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

void OldInput::pressed_key(char key) {
    Log(key);
}

void OldInput::subscribe_view(OldView* view) {
	_subscribed_views.push_back(view);
}

void OldInput::unsubscribe_view(OldView* view) {
	_subscribed_views.remove(view);
}
