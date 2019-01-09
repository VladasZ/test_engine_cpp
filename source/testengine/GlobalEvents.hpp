//
//  Events.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "Size.hpp"

#include "Event.hpp"

struct Events {
//	static inline Event<> frame_drawn;
//	static inline Event<ui::Point> touch;
    static inline Event<ui::Point> cursor_moved;
//	static inline Event<ui::Size> on_screen_size_change;
};
