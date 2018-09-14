//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Input.hpp"
#include "AnalogStickView.hpp"
#include "ScrollView.hpp"
#include "Macro.hpp"
#include "Label.hpp"
#include "System.hpp"
#include "ImageView.hpp"
#include "Glyph.hpp"
#include "DrawingView.hpp"
#include "FrameBuffer.hpp"
#include "StackView.hpp"
#include "TestView.hpp"
#include "ScrollView.hpp"
#include "SliderView.hpp"

ScrollView* scrollView;

void RootView::setup() {
    
#if DEBUG_VIEW
    addSubview(new DebugInfoView());
#endif
    

	SliderView* slider = (new SliderView({ 50, 400 }));
    slider->addLayout(L::CenterV(), L::Right());
        

	Label* sliderValueLabel = new Label({ 50, 50 });
	sliderValueLabel->addLayout(L::Bottom(20, slider), L::CenterH(slider));
	sliderValueLabel->setText("30");

	slider->onValueChanged.subscribe([=](float value) {
		sliderValueLabel->setText(std::to_string(value));
	});

	addSubview(sliderValueLabel);
    addSubview(slider);
}

