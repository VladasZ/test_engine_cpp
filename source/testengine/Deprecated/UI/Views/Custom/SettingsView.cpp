//
//  SettingsView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/16/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "SettingsView.hpp"

void SettingsView::setup() {
    
    static ui::Size size = { 50, 350 };
    
    _xSlider = new LabeledSliderView(size);
    _ySlider = new LabeledSliderView(size);
    _zSlider = new LabeledSliderView(size);
	_fovSlider = new LabeledSliderView(size);
    _scaleSlider = new LabeledSliderView(size);
    _nearSlider = new LabeledSliderView(size);
    _farSlider = new LabeledSliderView(size);

    _xSlider->setCaption("X");
    _ySlider->setCaption("Y");
    _zSlider->setCaption("Z");
	_fovSlider->setCaption("FOV");
    _scaleSlider->setCaption("Scl");
    _nearSlider->setCaption("Near");
    _farSlider->setCaption("Far");

    _xSlider->add_layout(L::Left(), L::CenterV());
    _ySlider->add_layout(L::Left(10, _xSlider), L::CenterV());
    _zSlider->add_layout(L::Left(10, _ySlider), L::CenterV());
	_fovSlider->add_layout(L::Left(10, _zSlider), L::CenterV());
    _scaleSlider->add_layout(L::Left(10, _fovSlider), L::CenterV());
    _nearSlider->add_layout(L::Left(10, _scaleSlider), L::CenterV());
    _farSlider->add_layout(L::Left(10, _nearSlider), L::CenterV());

    add_subview(_xSlider);
    add_subview(_ySlider);
    add_subview(_zSlider);
	add_subview(_fovSlider);
    add_subview(_scaleSlider);
    add_subview(_nearSlider);
    add_subview(_farSlider);

    _xSlider->onValueChanged.link(onX);
    _ySlider->onValueChanged.link(onY);
    _zSlider->onValueChanged.link(onZ);
	_fovSlider->onValueChanged.link(onFov);
    _scaleSlider->onValueChanged.link(onScale);
    _nearSlider->onValueChanged.link(onNear);
    _farSlider->onValueChanged.link(onFar);
}
