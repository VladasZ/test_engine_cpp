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

class View;

#define INPUT_PARAMETERS float x, float y, TouchID id

using TouchID = long;

class Input final {
    
    Input();

	static inline Array<View*> _subscribedViews;
    
public:
    
#if GLFW
    
    static Point cursorPosition;
    static bool mouseKeyIsPressed;
    
#endif
    
    static void initialize();
    
    static void touchBegan(INPUT_PARAMETERS = 0);
    static void touchMoved(INPUT_PARAMETERS = 0);
    static void touchEnded(INPUT_PARAMETERS = 0);
    static void pressedKey(const char &key);

	static void subscribeView(View* view);
	static void unsubscribeView(View* view);
};
