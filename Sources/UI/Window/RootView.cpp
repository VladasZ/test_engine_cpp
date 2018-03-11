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

static MoveView *moveView;


void RootView::setup() {
    
    moveView = new MoveView(226, 150);
    moveView->autolayoutMask = Autolayout::BotLeft;
    addSubview(moveView);
}

void RootView::draw() {
    View::draw();
    
}
