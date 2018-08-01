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

AnalogStickView::AnalogStickView() : DrawingView({ SIZE, SIZE }) { }

void AnalogStickView::setup() {
    auto outerPath = Path::circleWith(_frame.size.center(), _frame.size.width);
    outerPath->_color = Color::black;
    addPath(outerPath);

    auto outlinePath = Path::circleWith(_frame.size.center(), _frame.size.width - OUTLINE_WIDTH);
    outlinePath->_color = Color::white;
    addPath(outlinePath);

    directionStick = new DrawingView({ STICK_VIEW_SIZE, STICK_VIEW_SIZE });
    directionStick->setCenter(_frame.size.center());
    addSubview(directionStick);

    directionStick->addPath([&]() {
        auto path = Path::circleWith(directionStick->frame().size.center(),
                                     STICK_VIEW_SIZE);
        path->_color = Color::black;
        return path;
    }());
    
    directionStick->addPath([&]() {
        auto path = Path::circleWith(directionStick->frame().size.center(),
                                     STICK_VIEW_SIZE - OUTLINE_WIDTH);
        path->_color = Color::lightGray;
        return path;
    }());
    
    Input::onTouchBegan.subscribe(this, [&](const Point &point, int id) {
        _touchID = id;
    });

    Input::onTouchMoved.subscribe(this, [&](const Point &point, int id) {
        onTouchMoved(point);
    });
    
    Input::onTouchEnded.subscribe(this, [&](Point point, int id) {
        _touchID = -1;
        directionStick->setCenter(_frame.size.center());
        onDirectionChange(Point());
    });
}

void AnalogStickView::onTouchMoved(const Point &touch) {
    
    float maxLenght = _frame.size.height / 2;
    
    Point touchPosition = localPointFrom(touch);
    Point vector = touchPosition - _frame.size.center();
    
    if (vector.length() > maxLenght) {
        vector = vector.withLength(maxLenght);
        touchPosition = _frame.size.center() + vector;
    }
    
    directionStick->setCenter(touchPosition);
    onDirectionChange(vector * 0.1f);
}
