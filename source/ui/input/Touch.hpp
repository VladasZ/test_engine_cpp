//
//  Touch.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 8/21/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <stdint.h>

#include "Point.hpp"
#include "Target.hpp"

#if DESKTOP_BUILD
#include "Mouse.hpp"
#endif

namespace ui {

class Touch {
public:

	static inline constexpr int no_id = -1;

    enum Event {
        Began,
        Moved,
        Ended
    };

    int id;
    gm::Point position;
    Event event;

#if DESKTOP_BUILD
    Mouse::Button button;

    Touch(int id, const gm::Point& position, Event event, Mouse::Button button);
#else
    Touch(int id, const gm::Point& position, Event event);
#endif

#if DESKTOP_BUILD
    bool is_left_click() const;
    bool is_middle_click() const;
    bool is_right_click() const;
#endif

    bool is_began() const;
    bool is_moved() const;
    bool is_ended() const;

    Touch* clone() const;

    std::string event_string() const;
    std::string to_string() const;
};

}
