//
//  ScrollView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Macro.hpp"
#include "Debug.hpp"
#include "Label.hpp"
#include "Input.hpp"
#include "Buffer.hpp"
#include "ScrollView.hpp"
#include "FrameBuffer.hpp"

ScrollView::ScrollView() : ScrollView({ 0, 0, 0, 0 }) {}

ScrollView::ScrollView(const Rect &rect) : View(rect) {
    _content_size = rect.size;
    _setFramebuffer(_content_size);
}

void ScrollView::setContentOffset(const Point &offset) {
    _content_offset = offset;
    _needsDraw = true;
}

ScrollView* ScrollView::_setFramebuffer(const Size& size) {
    _frameBuffer = new FrameBuffer(size);
    _ownsFramebuffer = true;
    return this;
}

void ScrollView::setup() {
    
    Debug::infoLabel->setText("hello");
    
    static Point beganPoint;
    static Point movedPoint;
    
    Input::onTouchBegan.subscribe(this, [&](Point point, TouchID id) {
        Debug::infoLabel->setText("Began x: "_s + point.x + " y: " + point.y);
        beganPoint = point;
    });
    
    Input::onTouchMoved.subscribe(this, [&](Point point, TouchID id) {
        
        Point current = beganPoint - point;
        beganPoint = point;
        
        this->setOrigin(this->frame().origin - current);
        
        Debug::infoLabel->setText("Moved x: "_s + current.x + " y: " + current.y);
    });
    
    Input::onTouchEnded.subscribe(this, [&](Point point, TouchID id) {
        Debug::infoLabel->setText("Ended x: "_s + point.x + " y: " + point.y);
    });
}

Buffer* ScrollView::_getBuffer() const {
    
    const auto heightRatio = _frame.size.height / _content_size.height;
    const auto widthRatio  = _frame.size.width / _content_size.width;

    const Rect rect {
        -1 + 2 * (1 - heightRatio),
        -1 + 2 * (1 - heightRatio),
             2 * widthRatio,
             2 * heightRatio
    };
    
    return new Buffer(BufferData::fromRectToImage(rect),
                      BufferConfiguration::_2_2);
}

void ScrollView::draw() {
    if (_needsLayout) layout();
        
    drawSubviews();
    
    UNPRIVATE(superview)->_frameBuffer->draw([&]{
        GL::setViewport(_frameInFrameBuffer);
        Shader::uiTexture.use();
        _frameBuffer->getImage()->bind();
        _getBuffer()->draw();
        GL::unbindImage();
#if DRAW_DEBUG_FRAMES
        Shader::ui.use();
        Shader::ui.setUniformColor(C::turquoise);
        Buffer::fullscreenOutline->draw();
#endif
    });
}


