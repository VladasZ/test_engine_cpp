//
//  AnalogStickView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "AnalogStickView.hpp"
#include "Event.hpp"

using namespace std;

static const float SIZE = 140;
static const float OUTLINE_WIDTH = 10;
static const float STICK_VIEW_SIZE = SIZE / 2;

AnalogStickView::AnalogStickView() : DrawingView(SIZE, SIZE) { }

void AnalogStickView::setup() {
    auto outerPath = Path::circleWith(frame.size.center(), frame.size.width);
    outerPath->color = Color::black;
    addPath(outerPath);

    auto outlinePath = Path::circleWith(frame.size.center(), frame.size.width - OUTLINE_WIDTH);
    outlinePath->color = Color::white;
    addPath(outlinePath);

    directionStick = new DrawingView(STICK_VIEW_SIZE, STICK_VIEW_SIZE);
    directionStick->setCenter(frame.size.center());
    addSubview(directionStick);

    directionStick->addPath([this]() {
        auto path = Path::circleWith(directionStick->frame.size.center(),
                                     STICK_VIEW_SIZE);
        path->color = Color::black;
        return path;
    }());
    
    directionStick->addPath([this]() {
        auto path = Path::circleWith(directionStick->frame.size.center(),
                                     STICK_VIEW_SIZE - OUTLINE_WIDTH);
        path->color = Color::lightGray;
        return path;
    }());
    
    Input::onTouchBegan.subscribe(this, [this](const Point &point, int id) {
        _touchID = id;
    });

    Input::onTouchMoved.subscribe(this, [this](const Point &point, int id) {
        onTouchMoved(point);
    });
    
    Input::onTouchEnded.subscribe(this, [this](Point point, int id) {
        _touchID = -1;
        directionStick->setCenter(frame.size.center());
        if (action) action(Point());
    });
}

void AnalogStickView::onTouchMoved(const Point &touch) {
    
    float maxLenght = frame.size.height / 2;
    
    Point touchPosition = localPointFrom(touch);
    Point vector = touchPosition - frame.size.center();
    
    if (vector.length() > maxLenght) {
        vector = vector.withLength(maxLenght);
        touchPosition = frame.size.center() + vector;
    }
    
    directionStick->setCenter(touchPosition);
    if (action) action(vector * 0.1f);
}

void AnalogStickView::onDirectionChange(const function<void (const Point &)> &action) {
    this->action = action;
}

