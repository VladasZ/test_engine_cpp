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

    view = (new View({ 100, 100 }))
        ->addLayout(Layout::CenterH(), Layout::Top(100))
        ->setColor(Color::blue);

    addSubview(view);

    addSubview(
        (new Label({ 50, 50 }))
        ->setText("1111111111")
        ->setColor(Color::green)
        ->addLayout(
            Layout::Bottom(10, view), 
            Layout::CenterH(view)
        )
    );

    addSubview(
        (new Label({ 50, 50 }))
        ->setText("2222222222")
        ->setColor(Color::green)
        ->addLayout(
            Layout::Left(10, view),
            Layout::CenterV(view)
        )
    );

    addSubview(
        (new Label({ 50, 50 }))
        ->setText("3333333333")
        ->setColor(Color::green)
        ->addLayout(
            Layout::Top(10, view),
            Layout::CenterH(view)
        )
    );

    addSubview(
        (new Label({ 50, 50 }))
        ->setText("4444444444")
        ->setColor(Color::green)
        ->addLayout(
            Layout::Right(10, view),
            Layout::CenterV(view)
        )
    );


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
