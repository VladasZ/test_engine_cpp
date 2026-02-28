//
//  Mouse.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/19/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Target.hpp"

#ifdef DESKTOP_BUILD

#include <magic_enum.hpp>

#include "Input.hpp"
#include "Touch.hpp"
#include "Mouse.hpp"

using namespace ui;
using namespace gm;
using namespace std;
using namespace magic_enum;


static Touch* mouse_touch = new Touch(1, { }, Touch::Event::Ended, Mouse::Button::Left);


void Mouse::set_position(const Point& _position) {
	frame_shift = _position - Mouse::position;
	Mouse::position = _position;
	on_moved(_position);
   if (button_state == ButtonState::Up) {
       Input::hover_moved(_position);
   } else {
       mouse_touch->position = _position;
       mouse_touch->event = Touch::Event::Moved;
       Input::process_touch_event(mouse_touch);
   }
}

void Mouse::set_button_state(Button _button, ButtonState state) {
    button_state = state;

    auto event = state == ButtonState::Down ? Touch::Event::Began : Touch::Event::Ended;

    if (event == Touch::Event::Began) {
        static int id = 0;
        mouse_touch->id = id++;
    }

    mouse_touch->event = event;
    mouse_touch->position = position;
    mouse_touch->button = _button;

    Input::process_touch_event(mouse_touch);
}

string Mouse::to_string() const {
    return string() +
            "Button: "    + string(enum_name(button)) +
            " State: "    + string(enum_name(button_state)) +
            " Position: " + position.to_string();
}

#endif
