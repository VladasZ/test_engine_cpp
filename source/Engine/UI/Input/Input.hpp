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

class Button;
class View;

#define INPUT_PARAMETERS float x, float y, TouchID id

using TouchID = long;

typedef ConditionalEvent<View, TestEngine::Point, TouchID> TouchEvent;

class Input final {
    
    Input();
    
public:
    
#if GLFW
    
    static Point cursorPosition;
    static bool mouseKeyIsPressed;
    
#endif
    
    static void initialize();
    
    static void touchBegan(INPUT_PARAMETERS);
    static void touchMoved(INPUT_PARAMETERS);
    static void touchEnded(INPUT_PARAMETERS);
    static void pressedKey(const char &key);
    
    static TouchEvent onTouchBegan;
    static TouchEvent onTouchMoved;
    static TouchEvent onTouchEnded;
};