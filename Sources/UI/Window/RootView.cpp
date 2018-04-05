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

static MoveView *moveView;

static AnalogStickView *stickView;
static AnalogStickView *stickView2;

static View *testView;

void RootView::setup() {
    
    moveView = new MoveView(226, 150);
    moveView->autolayoutMask = Autolayout::BotLeft;
    addSubview(moveView);
    
    
    stickView = new AnalogStickView();
    stickView->autolayoutMask = Autolayout::BotRight;
    
    stickView->onDirectionChange([](const Point &point){
        Events::moveControl(point);
    });
    
    addSubview(stickView);
    
    stickView2 = new AnalogStickView();
    stickView2->autolayoutMask = Autolayout::TopRight;
    addSubview(stickView2);
    
    testView = new View(300, 300, 100, 100);
    testView->color = Color::green;
    
    
    Events::moveControl.subscribe(nullptr, [](const Point &point) {
        testView->rotation = point.angle();
    });
    
    addSubview(testView);
    
}

void RootView::draw() {
    View::draw();
    
}

void RootView::layout() {
    View::layout();
    
    stickView->autolayoutMask = 0;
    
    stickView->setFrame(Rect(stickView->frame.origin.x - 28,
                             stickView->frame.origin.y - 28,
                             stickView->frame.size.width,
                             stickView->frame.size.height));
    
    stickView->autolayoutMask = Autolayout::BotRight;
}
