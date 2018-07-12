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

ScrollView *scrollView;

Button* btn;

void RootView::setup() {

    directionStick = new AnalogStickView();
    rotationStick = new AnalogStickView();

    scrollView = new ScrollView({ 0, 100, 500, 500 });
    scrollView->color = Color::lightGray;

    btn = new Button({ 100, 100 });
    btn->color = Color::white;

    btn->onTouch([] {

        glViewport(0, 0, 300, 300);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    });

    btn->autolayoutMask = Autolayout::TopRight;

    addSubview(btn);


    //View *subview = new View({ 300, 300 });
    //subview->color = Color::green;

    //View *subSubView = new View({ 100, 100, 100, 100 });
    //subSubView->color = Color::blue;

    //subview->addSubview(subSubView);

    //scrollView->addSubview(subview);

    FOR(20) {
        scrollView->addSubview(new View(Rect::random()));
        scrollView->subviews.back()->color = Color::random();
        scrollView->subviews.back()->addSubview(
            View::dummy()->addSubview(
            (new ImageView({ 30, 30 }))->setImage(Image::cat)->setAutolayoutMask(Autolayout::Center)
            )
        );

        scrollView->addSubview(
            (new ImageView(Rect::random()))
            //->setImage(Font::System->glyphForChar('A')->image)
            ->setImage(Image::cat)
            ->setColor(Color::random())
        );

        //ImageView *imageView = new ImageView(Rect::random());
        //imageView->image = Image::cat;
        //scrollView->addSubview(imageView);

        Label *label = new Label(Rect::random());
        label->setText("HELOWSTVO");
        label->color = Color::random();
        scrollView->addSubview(label);
    }


    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;

    static Point offset;

    directionStick->onDirectionChange.subscribe([&](auto point) {
        offset += point;
        scrollView->setContentOffset(offset);
    });

    addSubview(directionStick);
    addSubview(rotationStick);
    addSubview(scrollView);
}

void RootView::draw() {

    if (Window::FPS > 40) {
        scrollView->addSubview(new View(Rect::random()));
        scrollView->subviews.back()->color = Color::random();

        Log(View::exists());
    }

    layout();

    View::draw();
}

void RootView::layout() {
    View::layout();

    const float stickMargin = 16;

    directionStick->autolayoutMask = 0;
    rotationStick->autolayoutMask = 0;

    directionStick->setFrame(directionStick->frame.origin.x - stickMargin,
        directionStick->frame.origin.y - stickMargin,
        directionStick->frame.size.width,
        directionStick->frame.size.height);

    rotationStick->setFrame(rotationStick->frame.origin.x + stickMargin,
        rotationStick->frame.origin.y - stickMargin,
        rotationStick->frame.size.width,
        rotationStick->frame.size.height);

    directionStick->autolayoutMask = Autolayout::BotRight;
    rotationStick->autolayoutMask = Autolayout::BotLeft;
}
