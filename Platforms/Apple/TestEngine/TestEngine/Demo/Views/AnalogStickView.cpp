//
//  AnalogStickView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "AnalogStickView.hpp"


AnalogStickView::AnalogStickView(float size) : View(size, size) {
    color = Color::orange;
}

void AnalogStickView::setup() {
    
    outerCirclePath = new Path(Rect(0, 0, 100, 100));
    outerCirclePath->color = Color::green;
}

void AnalogStickView::layout() {
    View::layout();
    outerCirclePath->setOrigin(frame.origin);
}

void AnalogStickView::draw() {
    View::draw();
    
    outerCirclePath->draw();
}
