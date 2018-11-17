//
//  SliderView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "ImageView.hpp"
#include "SliderView.hpp"
#include "Log.hpp"

void SliderView::setup() {
    
    _color = C::gray;
    
    _topArrow = (new ImageView({ _frame.size.width, _frame.size.width }))
                    ->setImage(I::up);
    
    _bottomArrow = (new ImageView({ _frame.size.width, _frame.size.width }))
                    ->setImage(I::down);
    
    _slider = (new View({ _frame.size.width, _frame.size.height / 10 }));
    
    _slider->setColor(C::green);
    
    _sliderContentView = new View();
    _sliderContentView->setColor(C::blue);
    
    _sliderContentView->addSubview(_slider);
    
    addSubview(_topArrow);
    addSubview(_bottomArrow);
    addSubview(_sliderContentView);

	_topArrow->enableTouch();
	_bottomArrow->enableTouch();
	_sliderContentView->enableTouch();

	_topArrow->onTouch.subscribe([&](Touch touch) {
		if (!touch.isBegan()) return;
		this->setValue(this->value() + 0.02f);
	});

	_bottomArrow->onTouch.subscribe([&](Touch touch) {
		if (!touch.isBegan()) return;
		this->setValue(this->value() - 0.02f);
	});

	_sliderContentView->onTouch.subscribe([&](Touch touch) {
		auto height = _sliderContentView->frame().size.height;
		this->setValue(1 - touch.location.y / height);
	});
}

void SliderView::layout() {
    
    View::layout();
    
    auto sliderContentViewHeight = _frame.size.height - _frame.size.width / 2;
    auto sliderHeight = _frame.size.height / 10;
    
    _topArrow->setFrame({
        0,
        0,
        _frame.size.width,
        _frame.size.width
    });
    
    _sliderContentView->setFrame({
        0,
        _frame.size.width,
        _frame.size.width,
        sliderContentViewHeight
    });
    
    _slider->setFrame({
        0,
        (sliderContentViewHeight - sliderHeight) * (1 - _value / 1),
        _frame.size.width,
        sliderHeight
    });
    
    _bottomArrow->setFrame({
        0,
        _frame.size.width + sliderContentViewHeight,
        _frame.size.width,
        _frame.size.width
    });
    
    _needsLayout = false;
}

SliderView* SliderView::setValue(float value) {
	_value = value;

	if (_value > 1)
		_value = 1;

	if (_value < 0)
		_value = 0;

	_needsLayout = true;

	onValueChanged(_value);

	return this;
}
