//
//  Events.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Touch.hpp"

#include "Event.hpp"

struct Events {
    static inline ui::Event<> frame_drawn;
    static inline ui::Event<ui::Touch*> touch;
    static inline ui::Event<Point> cursor_moved;
    static inline ui::Event<Size> on_screen_size_change;
};
