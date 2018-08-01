//
//  AnalogStickView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "UI.hpp"

class AnalogStickView : public DrawingView {
  
    void setup() override;
    
    DrawingView* directionStick;
    
    void onTouchMoved(const Point &touch);
    
public:
        
    AnalogStickView();

    Event<const Point &> onDirectionChange;
};
