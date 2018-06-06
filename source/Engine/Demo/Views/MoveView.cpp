//
//  MoveView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "MoveView.hpp"

static Button *leftButton;
static Button *rightButton;
static Button *upButton;
static Button *downButton;

std::vector<Button *> buttons() {
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
    
    static const float speed = 10;
    
    //leftButton ->onTouch([]() { Events::onRotation(Point(Direction::Left,  speed)); });
    //rightButton->onTouch([]() { Events::onRotation(Point(Direction::Right, speed)); });
    //upButton   ->onTouch([]() { Events::onRotation(Point(Direction::Up,    speed)); });
    //downButton ->onTouch([]() { Events::onRotation(Point(Direction::Down,  speed)); });

    //for (auto button : buttons())
    //    button->onRelease([]() { Events::onRotation(Point()); });
}

void MoveView::layout() {
    View::layout();
    Size buttonSize = Size(frame.size.height / 2, frame.size.width / 3);
    for (auto button : buttons()) {
        button->frame.size = buttonSize;
        button->layout();
    }
}

