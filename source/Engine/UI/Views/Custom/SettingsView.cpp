//
//  SettingsView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/16/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "SettingsView.hpp"

void SettingsView::setup() {
    
    static Size size = { 50, 350 };
    
    _xSlider = new LabeledSliderView(size);
    _ySlider = new LabeledSliderView(size);
    _zSlider = new LabeledSliderView(size);
	_fovSlider = new LabeledSliderView(size);
	_scaleSlider = new LabeledSliderView(size);

    _xSlider->setCaption("X");
    _ySlider->setCaption("Y");
    _zSlider->setCaption("Z");
	_fovSlider->setCaption("FOV");
	_scaleSlider->setCaption("Scl");

    _xSlider->addLayout(L::Left(), L::CenterV());
    _ySlider->addLayout(L::Left(10, _xSlider), L::CenterV());
    _zSlider->addLayout(L::Left(10, _ySlider), L::CenterV());
	_fovSlider->addLayout(L::Left(10, _zSlider), L::CenterV());
	_scaleSlider->addLayout(L::Left(10, _fovSlider), L::CenterV());

    addSubview(_xSlider);
    addSubview(_ySlider);
    addSubview(_zSlider);
	addSubview(_fovSlider);
	addSubview(_scaleSlider);

    _xSlider->onValueChanged.link(onX);
    _ySlider->onValueChanged.link(onY);
    _zSlider->onValueChanged.link(onZ);
	_fovSlider->onValueChanged.link(onFov);
	_scaleSlider->onValueChanged.link(onScale);
}
