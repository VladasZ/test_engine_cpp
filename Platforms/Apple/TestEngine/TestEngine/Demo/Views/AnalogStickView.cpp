//
//  AnalogStickView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "AnalogStickView.hpp"

#define OUTLINE_WIDTH 4

AnalogStickView::AnalogStickView(float size) : DrawingView(size, size) { }

void AnalogStickView::setup() {

    
    auto outerPath = Path::circleWith(frame.size.center(), frame.size.width);
    outerPath->color = Color::yellow;
    //addPath(outerPath);
    
    auto outlinePath = Path::circleWith(frame.size.center(), frame.size.width - OUTLINE_WIDTH);
    outlinePath->color = Color::green;
    addPath(outerPath);
    
}

