//
//  Keyboard.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 2/5/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Event.hpp"


namespace ui {

    using Key = int;

    class Keyboard {

    public:

        enum class Event {
            Up     = 0,
            Down   = 1,
            Repeat = 2
        };

        enum class Mod {
            None    = 0,
            Shift   = 1,
            Control = 2,
            Alt     = 8
        };

        static inline cu::Event<Key, Event> on_key_event;
        static inline cu::Event<Key> on_key_pressed;

        static inline cu::Event<> on_backspace;
        static inline cu::Event<Key> on_input;

        static void add_key_event(Key, Mod, Event);

    };

}
