//
//  Keyboard.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 2/5/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Keyboard.hpp"

using namespace ui;

static const int backspace = 259;


void Keyboard::add_key_event(Key key, Mod mod, Event event) {

    if (event == Event::Up) return;

    on_key_event(key, event);

    if (key == backspace) {
        on_backspace();
        return;
    }

    on_key_pressed(key);

    if (key > 128) return;

    if (mod == Mod::Shift) {
        on_input(key);
        return;
    }

    on_input(tolower(key));
}
