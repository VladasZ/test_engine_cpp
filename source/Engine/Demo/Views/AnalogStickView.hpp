//
//  AnalogStickView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"
#include <functional>
#include <vector>

class AnalogStickView : public DrawingView {
  
    std::function<void(const Point &)> action;
    void setup() override;
    
    DrawingView *directionStick;
    
    void onTouchMoved(const Point &touch);
    
public:
        
    AnalogStickView();
    
    void onDirectionChange(const std::function<void(const Point &)> &action);
};
