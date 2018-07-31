//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 08/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Input.hpp"
#include "MoveView.hpp"
#include "AnalogStickView.hpp"
#include "ScrollView.hpp"
#include "Macro.hpp"
#include "Label.hpp"
#include "System.hpp"
#include "ImageView.hpp"
#include "Glyph.hpp"
#include "DrawingView.hpp"
#include "FrameBuffer.hpp"

ImageView *imageView;

View *view;

void RootView::setup() {

    view = (new View({ 220, 220 }))
        ->addLayout(Layout::CenterH(), Layout::CenterV())
        ->setColor(Color::blue)
        ;

    addSubview(view);

    createSticks();
}

void RootView::createSticks() {

    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();

    directionStick->addLayout(Layout::Bottom(15), Layout::Right(15));
    rotationStick->addLayout(Layout::Bottom(15), Layout::Left(15));

    addSubview(directionStick);
    addSubview(rotationStick);
}
