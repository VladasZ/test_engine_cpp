//
//  SliderView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "OldView.hpp"

class SliderView : public OldView {
    
    OldView* _topArrow;
    OldView* _bottomArrow;
    OldView* _slider;
    OldView* _sliderContentView;

	float _value = 0;

public:
       
    using OldView::OldView;
    
    void setup() override;
    void layout() override;
	
	Event<float> onValueChanged;

	float value() const { return _value; }
	SliderView* setValue(float value);
};
