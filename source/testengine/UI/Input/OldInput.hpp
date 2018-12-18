//
//  Input.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"
#include "ConditionalEvent.hpp"

class OldView;

#define INPUT_PARAMETERS float x, float y, TouchID id

using TouchID = int64_t;

class OldInput final {
    
    OldInput();

	static inline Array<OldView*> _subscribed_views;
    
public:
    
#if GLFW
    
    static ui::Point cursor_position;
    static bool mouse_key_is_pressed;
    
#endif
    
    static void initialize();
    
    static void touch_began(INPUT_PARAMETERS = 0);
    static void touch_moved(INPUT_PARAMETERS = 0);
    static void touch_ended(INPUT_PARAMETERS = 0);
    static void pressed_key(char key);

	static void subscribe_view(OldView* view);
	static void unsubscribe_view(OldView* view);
};
