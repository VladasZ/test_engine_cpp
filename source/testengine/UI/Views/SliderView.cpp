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
    
    _slider->set_color(C::green);
    
    _sliderContentView = new View();
    _sliderContentView->set_color(C::blue);
    
    _sliderContentView->add_subview(_slider);
    
    add_subview(_topArrow);
    add_subview(_bottomArrow);
    add_subview(_sliderContentView);

	_topArrow->enable_touch();
	_bottomArrow->enable_touch();
	_sliderContentView->enable_touch();

	_topArrow->on_touch.subscribe([&](Touch touch) {
		if (!touch.isBegan()) return;
		this->setValue(this->value() + 0.02f);
	});

	_bottomArrow->on_touch.subscribe([&](Touch touch) {
		if (!touch.isBegan()) return;
		this->setValue(this->value() - 0.02f);
	});

	_sliderContentView->on_touch.subscribe([&](Touch touch) {
		auto height = _sliderContentView->frame().size.height;
		this->setValue(1 - touch.location.y / height);
	});
}

void SliderView::layout() {
    
    View::layout();
    
    auto sliderContentViewHeight = _frame.size.height - _frame.size.width / 2;
    auto sliderHeight = _frame.size.height / 10;
    
    _topArrow->set_size({
        _frame.size.width,
        _frame.size.width
    });
    
    _sliderContentView->set_frame({
        0,
        _frame.size.width,
        _frame.size.width,
        sliderContentViewHeight
    });
    
    _slider->set_frame({
        0,
        (sliderContentViewHeight - sliderHeight) * (1 - _value / 1),
        _frame.size.width,
        sliderHeight
    });
    
    _bottomArrow->set_frame({
        0,
        _frame.size.width + sliderContentViewHeight,
        _frame.size.width,
        _frame.size.width
    });
    
    _needs_layout = false;
}

SliderView* SliderView::setValue(float value) {
	_value = value;

	if (_value > 1)
		_value = 1;

	if (_value < 0)
		_value = 0;

	_needs_layout = true;

	onValueChanged(_value);

	return this;
}
