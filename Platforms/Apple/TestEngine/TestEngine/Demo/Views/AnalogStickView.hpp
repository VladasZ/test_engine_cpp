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
  
    function<void(Point)> action;
        
    void setup() override;
    
    vector<Path *> paths();
    
public:
        
    AnalogStickView(float size);
    
    void onDirectionChange(const function<void(Point)> &action);
};