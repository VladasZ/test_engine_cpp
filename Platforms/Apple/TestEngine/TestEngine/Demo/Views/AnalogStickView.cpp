//
//  AnalogStickView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "AnalogStickView.hpp"
#include "Event.hpp"

#define SIZE 140
#define OUTLINE_WIDTH 10
#define STICK_VIEW_SIZE (SIZE / 2.18)

AnalogStickView::AnalogStickView() : DrawingView(SIZE, SIZE) { }

void AnalogStickView::setup() {
    auto outerPath = Path::circleWith(frame.size.center(), frame.size.width);
    outerPath->color = Color::black;
    addPath(outerPath);

    auto outlinePath = Path::circleWith(frame.size.center(), frame.size.width - OUTLINE_WIDTH);
    outlinePath->color = Color::white;
    addPath(outlinePath);

    stickView = new DrawingView(STICK_VIEW_SIZE, STICK_VIEW_SIZE);
    stickView->setCenter(frame.size.center());
    addSubview(stickView);

    stickView->addPath([this]() {
        auto path = Path::circleWith(stickView->frame.size.center(), STICK_VIEW_SIZE);
        path->color = Color::black;
        return path;
    }());
    
    stickView->addPath([this]() {
        auto path = Path::circleWith(stickView->frame.size.center(), STICK_VIEW_SIZE - OUTLINE_WIDTH);
        path->color = Color::lightGray;
        return path;
    }());
    
    Input::onTouchBegan.subscribe(this, [this](const Point &point) {
        _touchID = 1;
        stickView->setCenter(localPointFrom(point));
    });
    
    Input::onTouchMoved.subscribe(this, [this](const Point &point) {
        stickView->setCenter(localPointFrom(point));
    });
    
    Input::onTouchEnded.subscribe(this, [this](Point poit) {
        _touchID = -1;
        stickView->setCenter(frame.size.center());
    });
}

