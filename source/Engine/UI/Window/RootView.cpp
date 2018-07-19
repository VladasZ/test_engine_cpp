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

void RootView::setup() {

    _frameBuffer = Window::rootFrameBuffer;

    addSubview(
        (new View({ 200, 200 }))
        ->setColor(Color::green)
        ->addLayout(Layout::Bottom(10), Layout::Left(10))
        ->edit([](auto view) {
        FOR(20000) {
            view->addSubview(View::dummy());
        }
    })
    );

    addSubview(
        (new ImageView({ 200, 200 }))
        ->setImage(Image::cat)
        ->addLayout(Layout::CenterH(), Layout::CenterV())
    );

    addSubview(
        (new Label({ 100, 20 }))
        ->setText("Hellofff")
        ->addLayout(Layout::Bottom(), Layout::Right())
    );

    createSticks();

#if DEBUG_VIEW
    debugInfoView = new DebugInfoView();
    addSubview(debugInfoView);
#endif
}

void RootView::draw() {
    _frameBuffer->draw([&] {
        View::draw();
        for (auto subview : this->subviews)
            static_cast<RootView *>(subview)->draw();
    });
    Window::resetViewport();
}

void RootView::createSticks() {

    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();

    directionStick->addLayout(Layout::Bottom(15), Layout::Right(15));
    rotationStick->addLayout(Layout::Bottom(15), Layout::Left(15));

    //addSubview(directionStick);
    //addSubview(rotationStick);
}
