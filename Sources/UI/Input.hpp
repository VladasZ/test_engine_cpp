//
//  Input.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

#define INPUT_PARAMETERS float x, float y

class Input {
    
    Input();
    
public:
    
    static void initialize();
    
    static void touchBegan(INPUT_PARAMETERS);
    static void touchMoved(INPUT_PARAMETERS);
    static void touchEnded(INPUT_PARAMETERS);
    static void pressedKey(const char &key);
};
