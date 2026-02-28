//
//  ui.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/5/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <string>

#include "Log.hpp"

#include "ui.hpp"
#include "Mouse.hpp"
#include "UIDrawer.hpp"

using namespace ui;

#if DESKTOP_BUILD
Mouse* const input::mouse = new Mouse();
#endif

static UIDrawer* _drawer;

UIDrawer* config::drawer() {
    if (_drawer == nullptr) {
        Fatal("Accessign nullptr ui::Drawer");
    }
    return _drawer;
}

void config::set_drawer(UIDrawer* drawer) {
	if (_drawer) {
        delete _drawer;
    }
	_drawer = drawer;
}
