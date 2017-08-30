//
//  Input.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "Point.hpp"
#include "Window.hpp"

void Input::touchBegan(double x, double y) {
    
    Window::touchBegan(Point(x, y));
}

void Input::touchMoved(double x, double y) {
    
}

void Input::touchEnded(double x, double y) {
    
}
