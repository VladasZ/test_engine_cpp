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

static View *greenView = new View(100, 100);
static View *blueView = new View(100, 100);
static ImageView *catView = new ImageView(100, 100);


void RootView::setup() {
    
    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();
    
    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;
    
    greenView->color = Color::green;
    blueView->color = Color::blue;

    catView->image = Image::cat;
    catView->setCenter(500, 300);

    blueView->setCenter(300, 300);
    
    addSubview(directionStick);
    addSubview(rotationStick);
    addSubview(greenView);
    addSubview(blueView);
    addSubview(catView);
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
