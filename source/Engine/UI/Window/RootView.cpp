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
FrameBuffer *frameBuffer;

void RootView::setup() {

    frameBuffer = new FrameBuffer({ 1000, 800 });


    imageView = (ImageView *)(new ImageView({ 900, 700 }))->setImage(frameBuffer->getImage())->setAutolayoutMask(Autolayout::Center);
    addSubview(imageView);


    view = (new View({ 50, 50 }))->setColor(Color::purple)->setAutolayoutMask(Autolayout::BotRight);
    addSubview(view);


    createSticks();
}

void RootView::draw() {

    frameBuffer->draw([&] {
     //   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        layout();
        View::draw();
    });

    View::draw();

}

void RootView::layout() {
    View::layout();

    //const float stickMargin = 16;

    //rotationStick->autolayoutMask = 0;

    //directionStick
    //    ->setAutolayoutMask(Autolayout::None)
    //    ->setFrame({
    //                directionStick->frame.origin.x - stickMargin,
    //                directionStick->frame.origin.y - stickMargin,
    //                directionStick->frame.size.width,
    //                directionStick->frame.size.height
    //        })
    //    ->setAutolayoutMask(Autolayout::BotRight)
    //    ;

    ////directionStick->setAutolayoutMask(Autolayout::None)
    ////    ->setFrame(
    ////        directionStick->frame.origin.x - stickMargin,
    ////        directionStick->frame.origin.y - stickMargin,
    ////        directionStick->frame.size.width,
    ////        directionStick->frame.size.height)
    ////    ->setAutolayoutMask(Autolayout::BotRight)
    ////    ;

    //rotationStick->setFrame({ rotationStick->frame.origin.x + stickMargin,
    //    rotationStick->frame.origin.y - stickMargin,
    //    rotationStick->frame.size.width,
    //    rotationStick->frame.size.height });

    //rotationStick->autolayoutMask = Autolayout::BotLeft;
}

void RootView::createSticks() {

    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();

    addSubview(directionStick->setAutolayoutMask(Autolayout::BotRight));
    addSubview(rotationStick->setAutolayoutMask(Autolayout::BotLeft));
}
