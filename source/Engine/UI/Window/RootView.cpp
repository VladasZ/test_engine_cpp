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

    imageView = (ImageView *)(new ImageView({ 200, 200 }))->setImage(Image::cat)->setAutolayoutMask(Autolayout::Center);
    addSubview(imageView);

    view = (new View({ 50, 50 }))->setColor(Color::purple)->setAutolayoutMask(Autolayout::BotRight);
    addSubview(view);


    GLuint fbo;
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);


    Image *renderImage = new Image(Size(1000, 1000));
    renderImage->bind();

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderImage->_get_GL_id(), 0); 



    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1000, 1000);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);



    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);





    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    glClearColor(0.1f, 0.8f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //  glViewport(0, 0, 800, 600);
    layout();
    draw();


    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    imageView->setImage(renderImage);




    createSticks();
}

void RootView::draw() {
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
