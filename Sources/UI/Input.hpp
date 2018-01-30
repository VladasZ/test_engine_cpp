//
//  Input.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

class Input {
    
    Input();
    
public:
    
    static void initialize();
    
    static void touchBegan(const Point &point);
    static void touchMoved(const Point &point);
    static void touchEnded(const Point &point);
    static void pressedKey(const char &key);
};
