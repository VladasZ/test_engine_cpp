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
#include "Events.hpp"


static AnalogStickView *directionStick;
static AnalogStickView *rotationStick;

void RootView::setup() {
    
    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();
    
    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;
    
    directionStick->onDirectionChange([](const Point &point) {
        Events::onRotation(point);
    });
    
    rotationStick->onDirectionChange([](const Point &point) {
        Events::onMove(point);
    });
    
    addSubview(directionStick);
    addSubview(rotationStick);
}

void RootView::draw() {
    View::draw();
    
}

void RootView::layout() {
    View::layout();
    
    const float stickMargin = 16;
    
    directionStick->autolayoutMask = 0;
    rotationStick->autolayoutMask = 0;

    directionStick->setFrame(Rect(directionStick->frame.origin.x - stickMargin,
                             directionStick->frame.origin.y - stickMargin,
                             directionStick->frame.size.width,
                             directionStick->frame.size.height));
    
    rotationStick->setFrame(Rect(rotationStick->frame.origin.x + stickMargin,
                              rotationStick->frame.origin.y - stickMargin,
                              rotationStick->frame.size.width,
                              rotationStick->frame.size.height));
    
    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;
}
