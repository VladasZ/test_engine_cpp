//
//  Touch.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 8/21/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <string>

#include "Log.hpp"
#include "Touch.hpp"

using namespace ui;
using namespace gm;

#if DESKTOP_BUILD
Touch::Touch(int id, const Point& position, Event event, Mouse::Button button)
    : id(id), position(position), event(event), button(button) { }
#else
Touch::Touch(int id, const Point& position, Touch::Event event)
    : id(id), position(position), event(event) { }
#endif

#if DESKTOP_BUILD
bool Touch::is_left_click() const {
    return button == Mouse::Button::Left;
}

bool Touch::is_middle_click() const {
    return button == Mouse::Button::Middle;
}

bool Touch::is_right_click() const {
    return button == Mouse::Button::Right;
}
#endif

bool Touch::is_began() const {
    return event == Event::Began;
}

bool Touch::is_moved() const {
    return event == Event::Moved;
}

bool Touch::is_ended() const {
    return event == Event::Ended;
}

Touch* Touch::clone() const {
#if DESKTOP_BUILD
    return new Touch(id, position, event, button);
#else
    return new Touch(id, position, event);
#endif
}

std::string Touch::event_string() const {
    if (is_began()) return "Began";
    if (is_moved()) return "Moved";
    if (is_ended()) return "Ended";
    Fatal("Invalid touch type");
}

std::string Touch::to_string() const {
    return position.to_string() + " " + event_string() + " id: " + std::to_string(id);
}
