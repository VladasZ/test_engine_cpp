//
//  SliderView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "View.hpp"

class SliderView : public View {
    
    View* _topArrow;
    View* _bottomArrow;
    View* _slider;
    View* _sliderContentView;

	float _value = 0;

public:
       
    using View::View;
    
    void setup() override;
    void layout() override;
	
	Event<float> onValueChanged;

	float value() const { return _value; }
	SliderView* setValue(float value);
};
