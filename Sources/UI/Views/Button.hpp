//
//  Button.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"

class Button : public View _MEMORY_MANAGED(Button) {
    
    friend Input;
        
    function<void()> action;
    
public:
    
    using View::View;
    
    void onTouch(function<void()> action);    
};
