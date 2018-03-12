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

static MoveView *moveView;

static AnalogStickView *stickView;


void RootView::setup() {
    
    moveView = new MoveView(226, 150);
    moveView->autolayoutMask = Autolayout::BotLeft;
    addSubview(moveView);
    
    stickView = new AnalogStickView(200);
    stickView->autolayoutMask = Autolayout::BotRight;
    addSubview(stickView);
}

void RootView::draw() {
    View::draw();
    
}
