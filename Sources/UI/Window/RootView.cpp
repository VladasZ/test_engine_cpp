//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"


static Label *helloLabel;
static Button *button;


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
    
    addSubview(button);
    
    button->onTouch([]() {
        Log("Helloooo!");
    });
}
