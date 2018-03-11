//
//  MoveView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "MoveView.hpp"
#include "Events.hpp"

static Button *leftButton;
static Button *rightButton;
static Button *upButton;
static Button *downButton;

vector<Button *> buttons() {
    return { leftButton, rightButton, upButton, downButton };
}


void MoveView::setup() {
    leftButton  = new Button();
    rightButton = new Button();
    upButton    = new Button();
    downButton  = new Button();
    
    leftButton ->setImage(new Image("left.png"));
    rightButton->setImage(new Image("right.png"));
    upButton   ->setImage(new Image("up.png"));
    downButton ->setImage(new Image("down.png"));
    
    addSubview(leftButton);
    addSubview(rightButton);
    addSubview(upButton);
    addSubview(downButton);
    
    leftButton ->autolayoutMask = Autolayout::BotLeft;
    rightButton->autolayoutMask = Autolayout::BotRight;
    upButton   ->autolayoutMask = Autolayout::CenterHorizontally | Autolayout::StickToTop;
    downButton ->autolayoutMask = Autolayout::CenterHorizontally | Autolayout::StickToBottom;
    
    
    static int speed = 10;
    
    leftButton ->onTouch([]() { Events::moveControl(Point(Direction::left,  speed)); });
    rightButton->onTouch([]() { Events::moveControl(Point(Direction::right, speed)); });
    upButton   ->onTouch([]() { Events::moveControl(Point(Direction::up,    speed)); });
    downButton ->onTouch([]() { Events::moveControl(Point(Direction::down,  speed)); });

    for (auto button : buttons())
        button->onRelease([]() { Events::moveControl(Point()); });
}

void MoveView::layout() {
    View::layout();
    Size buttonSize = Size(frame.size.height / 2, frame.size.width / 3);
    for (auto button : buttons()) {
        button->frame.size = buttonSize;
        button->color = Color::green;
        button->layout();
    }
}

