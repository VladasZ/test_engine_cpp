//
//  AnalogStickView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"

class AnalogStickView : public DrawingView {
  
    function<void(const Point &)> action;
    void setup() override;
    
    DrawingView *directionStick;
    
    void onTouchMoved(const Point &touch);
    
public:
        
    AnalogStickView();
    
    void onDirectionChange(const function<void(const Point &)> &action);
};
