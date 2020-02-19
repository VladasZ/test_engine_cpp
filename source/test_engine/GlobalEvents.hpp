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
    static inline cu::Event<> frame_drawn;
    static inline cu::Event<> screen_did_appear;
    static inline cu::Event<gm::Size> on_screen_size_change;
};
