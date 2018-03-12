//
//  AnalogStickView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "UI.hpp"

class AnalogStickView : public View {
  
    function<void(Point)> action;
    
    Path *outerCirclePath;
    
    void setup() override;
    void draw() override;
    void layout() override;
    
public:
        
    AnalogStickView(float size);
    
    void onDirectionChange(const function<void(Point)> &action);
};
