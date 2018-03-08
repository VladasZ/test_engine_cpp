//
//  Button.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Button.hpp"


void Button::onTouch(function<void()> action) {
    Input::buttons.push_back(this);
    this->action = action;
}
