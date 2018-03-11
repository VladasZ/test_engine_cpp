//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Input.hpp"

void RootView::setup() {

    helloLabel = new Label(100, 40);
    helloLabel->autolayoutMask = Autolayout::TopRight;
    helloLabel->setFont(Font::System->withSize(50));
    helloLabel->setText("Hello!");
    helloLabel->color = Color::orange;
    addSubview(helloLabel);
    
    button = new Button(200, 200);
    button->autolayoutMask = Autolayout::Center;
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
