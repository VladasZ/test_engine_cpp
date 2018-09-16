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
#include "LabeledSliderView.hpp"

ScrollView* scrollView;

void RootView::setup() {
    
#if DEBUG_VIEW
    addSubview(new DebugInfoView());
#endif
    

    LabeledSliderView* lSlider = new LabeledSliderView({ 40, 200 });
    lSlider->addLayout(L::Left(20), L::CenterV());
    lSlider->setCaption("rglak");
    
    addSubview(lSlider);
}

