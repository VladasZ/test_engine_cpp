//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Input.hpp"

static Button *button;
static Path *testPath;

void RootView::setup() {
    
    button = new Button(50, 100);
    button->autolayoutMask = Autolayout::TopRight;
    button->color = Color::blue;
    button->setText("Touch me!");
    button->setImage(Image::cat);
    
    addSubview(button);
    
    button->onTouch([]() {
        Alert::show("UUU!");
    });
    
    testPath = new Path();
    
    testPath->color = Color::green;
    
    testPath->lineWidth = 6;
    
    testPath->addPoint(100, 100);
    testPath->addPoint(100, 200);
    testPath->addPoint(200, 200);
    testPath->addPoint(200, 100);
    

    testPath = new Path(Rect(100, 100, 100, 100));
    testPath->color = Color::green;
    
    Input::onTouchMoved([this](Point point){
        testPath->addPoint(point);
    });
}

void RootView::draw() {
    View::draw();
    
    testPath->draw();
}
