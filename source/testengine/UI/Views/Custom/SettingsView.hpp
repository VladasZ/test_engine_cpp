//
//  SettingsView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/16/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "LabeledSliderView.hpp"

class SettingsView : public View {
    
    
    LabeledSliderView* _xSlider;
    LabeledSliderView* _ySlider;
    LabeledSliderView* _zSlider;
    
    LabeledSliderView* _fovSlider;

	LabeledSliderView* _scaleSlider;

    LabeledSliderView* _nearSlider;
    LabeledSliderView* _farSlider;

    
public:
    
    using View::View;
    
    Event<float> onX;
    Event<float> onY;
    Event<float> onZ;
	Event<float> onFov;
    Event<float> onScale;
    Event<float> onNear;
    Event<float> onFar;

    void setup() override;

};
