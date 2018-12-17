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

class LabeledSliderView : public OldView {
    
    SliderView* _sliderView = nullptr;
    Label* _valueLabel = nullptr;
    Label* _captionLabel = nullptr;
    std::string _caption = "";
    
public:
    
    using OldView::OldView;
    
    Event<float> onValueChanged;
    
    void setup() override;
    
    void layout() override;
    
    void setCaption(const std::string& caption);
    
};
