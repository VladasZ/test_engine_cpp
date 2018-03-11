//
//  Button.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Button.hpp"

void Button::setText(const String &text) {
    if (label == nullptr) {
        label = new Label();
        label->autolayoutMask = Autolayout::Center;
        addSubview(label);
    }
    label->setText(text);
    layout();
}

void Button::setImage(Image *image) {
    if (imageView == nullptr) {
        imageView = new ImageView(frame.withZeroOrigin());
        imageView->autolayoutMask = Autolayout::Background;
        insertSubviewAt(0, imageView);
    }
    
    imageView->image = image;
}

bool Button::containsPoint(const Point &point) const {
    return absoluteFrame().contains(point);
}

void Button::onTouch(function<void()> action) {
    Input::buttons.push_back(this);
    touchAction = action;
}

void Button::onRelease(function<void()> action) {
    releaseAction = action;
}
