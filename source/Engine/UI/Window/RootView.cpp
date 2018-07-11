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
#include "Label.hpp"

ScrollView *scrollView;

void RootView::setup() {
    
    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();

    scrollView = new ScrollView({ 500, 500 });

    scrollView->color = Color::lightGray;


    View *subview = new View({ 300, 300 });
    subview->color = Color::green;

    View *subSubView = new View({ 100, 100, 100, 100 });
    subSubView->color = Color::blue;

    subview->addSubview(subSubView);

    scrollView->addSubview(subview);

    FOR(10) {
        scrollView->addSubview(new View (Rect::random()));
        scrollView->subviews.back()->color = Color::random();

        Label *label = new Label(Rect::random());

        label->setText("HELO fdsk gufd9s8 ugsdfjg ;sld");


        label->color = Color::random();

        scrollView->addSubview(label);
    }

    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;

    static Point offset;

    directionStick->onDirectionChange.subscribe([&](auto point) {
        offset += point;
        scrollView->setContentOffset(offset);
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
