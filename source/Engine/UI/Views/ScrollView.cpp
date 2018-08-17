//
//  ScrollView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Macro.hpp"
#include "Debug.hpp"
#include "Label.hpp"
#include "ScrollView.hpp"

ScrollView::ScrollView() : ScrollView({ 0, 0, 0, 0 }) {}

ScrollView::ScrollView(const Rect &rect) : View(rect) {
    _content_size = rect.size;
    _setFramebuffer();
}

void ScrollView::setContentOffset(const Point &offset) {
    _content_offset = offset;
    _needsDraw = true;
}

void ScrollView::setup() {

    Debug::infoLabel->setText("hello");
    
    static Point beganPoint;
    static Point movedPoint;

    Input::onTouchBegan.subscribe(this, [&](Point point, TouchID id) {
        Debug::infoLabel->setText("Began x: "_s + point.x + " y: " + point.y);
        beganPoint = point;
    });
    
    Input::onTouchMoved.subscribe(this, [&](Point point, TouchID id) {
        
        Point current = beganPoint - point;
        beganPoint = point;
        
        this->setOrigin(this->frame().origin - current);
        
        Debug::infoLabel->setText("Moved x: "_s + current.x + " y: " + current.y);
    });
    
    Input::onTouchEnded.subscribe(this, [&](Point point, TouchID id) {
        Debug::infoLabel->setText("Ended x: "_s + point.x + " y: " + point.y);
    });
}
