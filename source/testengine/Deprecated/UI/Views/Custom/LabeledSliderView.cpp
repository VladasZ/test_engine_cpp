//
//  LabeledSliderView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/15/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "LabeledSliderView.hpp"

void LabeledSliderView::setup() {
    
    _valueLabel = new Label();
    _valueLabel->setText("0");
    
    _sliderView = new SliderView();
    
    _captionLabel = new Label();
    _captionLabel->setText(_caption);
    
    add_subview(_valueLabel);
    add_subview(_sliderView);
    add_subview(_captionLabel);
    
    _sliderView->onValueChanged.subscribe([&](float value){
        this->onValueChanged(value);
        this->_valueLabel->setText(String::from_float(value));
    });
}

void LabeledSliderView::layout() {
    
    OldView::layout();
    
    _valueLabel->set_frame({
        0,
        0,
        _frame.size.width,
        _frame.size.width
    });
    
    _sliderView->set_frame({
        0,
        _frame.size.width,
        _frame.size.width,
        _frame.size.height - _frame.size.width * 2
    });
    
    _captionLabel->set_frame({
        0,
        _sliderView->frame().max_y() + _frame.size.width * 1.5f,
        _frame.size.width,
        _frame.size.width
    });
    
    //_needsLayout = false;
}

void LabeledSliderView::setCaption(const String& caption) {
    _caption = caption;
    if (_captionLabel)
        _captionLabel->setText(caption);
}
