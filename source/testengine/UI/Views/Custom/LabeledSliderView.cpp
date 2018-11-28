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
    
    addSubview(_valueLabel);
    addSubview(_sliderView);
    addSubview(_captionLabel);
    
    _sliderView->onValueChanged.subscribe([&](float value){
        this->onValueChanged(value);
        this->_valueLabel->setText(String::fromFloat(value));
    });
}

void LabeledSliderView::layout() {
    
    View::layout();
    
    _valueLabel->setFrame({
        0,
        0,
        _frame.size.width,
        _frame.size.width
    });
    
    _sliderView->setFrame({
        0,
        _frame.size.width,
        _frame.size.width,
        _frame.size.height - _frame.size.width * 2
    });
    
    _captionLabel->setFrame({
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
