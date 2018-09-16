//
//  LabeledSliderView.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/15/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"
#include "SliderView.hpp"

class LabeledSliderView : public View {
    
    SliderView* _sliderView;
    Label* _valueLabel;
    Label* _captionLabel;
    String _caption;
    
public:
    
    using View::View;
    
    Event<float> onValueChanged;
    
    void setup() override;
    
    void layout() override;
    
    void setCaption(const String& caption);
    
};
