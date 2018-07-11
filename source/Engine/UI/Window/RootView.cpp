//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Input.hpp"
#include "MoveView.hpp"
#include "AnalogStickView.hpp"
#include "ScrollView.hpp"
#include "Macro.hpp"

ScrollView *scrollView;

void RootView::setup() {
    
    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();

    scrollView = new ScrollView({ 500, 500 });

    scrollView->color = Color::lightGray;

    FOR(10) {
        scrollView->addSubview(new View (Rect::random()));
        scrollView->subviews.back()->color = Color::random();
    }

    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;

    directionStick->onDirectionChange.subscribe([&](auto point) {
        scrollView->setContentOffset(point);
    });
    
    addSubview(directionStick);
    addSubview(rotationStick);
    addSubview(scrollView);
}

void RootView::draw() {
    View::draw();
    
}

void RootView::layout() {
    View::layout();
    
    const float stickMargin = 16;
    
    directionStick->autolayoutMask = 0;
    rotationStick->autolayoutMask = 0;

    directionStick->setFrame(directionStick->frame.origin.x - stickMargin,
                             directionStick->frame.origin.y - stickMargin,
                             directionStick->frame.size.width,
                             directionStick->frame.size.height);
    
    rotationStick->setFrame(rotationStick->frame.origin.x + stickMargin,
                              rotationStick->frame.origin.y - stickMargin,
                              rotationStick->frame.size.width,
                              rotationStick->frame.size.height);
    
    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;
}
