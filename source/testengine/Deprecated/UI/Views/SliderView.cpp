//
//  SliderView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "OldInput.hpp"
#include "OldImageView.hpp"
#include "SliderView.hpp"
#include "Log.hpp"

void SliderView::setup() {
    
    _color = ui::C::gray;
    
    _topArrow = (new OldImageView({ _frame.size.width, _frame.size.width }))
                    ->set_image(Image::up);
    
    _bottomArrow = (new OldImageView({ _frame.size.width, _frame.size.width }))
                    ->set_image(Image::down);
    
    _slider = (new OldView({ _frame.size.width, _frame.size.height / 10 }));
    
    _slider->set_color(ui::C::green);
    
    _sliderContentView = new OldView();
    _sliderContentView->set_color(ui::C::blue);
    
    _sliderContentView->add_subview(_slider);
    
    add_subview(_topArrow);
    add_subview(_bottomArrow);
    add_subview(_sliderContentView);

	_topArrow->enable_touch();
	_bottomArrow->enable_touch();
	_sliderContentView->enable_touch();

	_topArrow->on_touch.subscribe([&](Touch touch) {
		if (!touch.is_began()) return;
        this->set_value(this->value() + 0.02f);
	});

	_bottomArrow->on_touch.subscribe([&](Touch touch) {
		if (!touch.is_began()) return;
        this->set_value(this->value() - 0.02f);
	});

	_sliderContentView->on_touch.subscribe([&](Touch touch) {
		auto height = _sliderContentView->frame().size.height;
        this->set_value(1 - touch.location.y / height);
	});
}

void SliderView::layout() {
    
    OldView::layout();
    
    auto slider_content_view_height = _frame.size.height - _frame.size.width / 2;
    auto slider_height = _frame.size.height / 10;
    
    _topArrow->set_size({
        _frame.size.width,
        _frame.size.width
    });
    
    _sliderContentView->set_frame({
        0,
        _frame.size.width,
        _frame.size.width,
        slider_content_view_height
    });
    
    _slider->set_frame({
        0,
        (slider_content_view_height - slider_height) * (1 - _value / 1),
        _frame.size.width,
        slider_height
    });
    
    _bottomArrow->set_frame({
        0,
        _frame.size.width + slider_content_view_height,
        _frame.size.width,
        _frame.size.width
    });
    
    _needs_layout = false;
}

SliderView* SliderView::set_value(float value) {
	_value = value;

	if (_value > 1)
		_value = 1;

	if (_value < 0)
		_value = 0;

	_needs_layout = true;

	onValueChanged(_value);

	return this;
}
