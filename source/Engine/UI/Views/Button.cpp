//
//  Button.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Button.hpp"

using namespace std;

void Button::setup() {
    Input::onTouchBegan.subscribe(this, [this](Point touch, int id) {
        _touchID = id;
        if (touchAction)
            touchAction();
    });
    
    Input::onTouchEnded.subscribe(this, [this](Point touch, int id) {
        _touchID = -1;
        if (releaseAction)
            releaseAction();
    });
}

void Button::setText(const std::string &text) {
    if (label == nullptr) {
        label = new Label();
        addSubview(label);
    }
    label->setText(text);
}

void Button::setImage(Image* image) {
    if (imageView == nullptr) {
        imageView = new ImageView(_frame.withZeroOrigin());
        insertSubviewAt(0, imageView);
    }
    
    imageView->setImage(image);
}

void Button::onTouch(function<void()> action) {
    touchAction = action;
}

void Button::onRelease(function<void()> action) {
    releaseAction = action;
}
