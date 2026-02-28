//
//  ui.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/5/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Font.hpp"
#include "Mouse.hpp"
#include "Target.hpp"
#include "UIDrawer.hpp"

#define DRAW_DEBUG_FRAMES
//#define LOG_TOUCHES


namespace ui {

    using Point = gm::Point;
    using Size  = gm::Size;
    using Rect  = gm::Rect;
    using Color = gm::Color;
    using Edge  = gm::Edge;

    struct config {
        static UIDrawer* drawer();
        static void set_drawer(UIDrawer* drawer);
        static inline Font* default_font = nullptr;
        static inline Color default_font_color = Color();
    };

#ifdef DESKTOP_BUILD
    struct input {
        static Mouse* const mouse;
    };
#endif

}
