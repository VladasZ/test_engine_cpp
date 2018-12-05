//
//  ScrollView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/11/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Debug.hpp"
#include "Label.hpp"
#include "Input.hpp"
#include "Buffer.hpp"
#include "Lifehack.hpp"
#include "ScrollView.hpp"
#include "FrameBuffer.hpp"


ScrollView::ScrollView() : ScrollView({ 0, 0, 0, 0 }) {}

ScrollView::ScrollView(const ui::Rect &rect) : OldView(rect) {
    _content_size = rect.size;
    _setFramebuffer(_content_size);
}

void ScrollView::setContentOffset(const ui::Point &offset) {
    _content_offset = offset;
    _need_draw = true;
}

ScrollView* ScrollView::_setFramebuffer(const ui::Size& size) {
    _frame_buffer = new FrameBuffer(size);
    _owns_framebuffer = true;
    return this;
}

void ScrollView::setup() {
    Debug::infoLabel->setText("hello");
}

Buffer* ScrollView::_getBuffer() const {
    
    const auto heightRatio = _frame.size.height / _content_size.height;
    const auto widthRatio  = _frame.size.width / _content_size.width;

    const ui::Rect rect {
        -1 + 2 * (1 - heightRatio),
        -1 + 2 * (1 - heightRatio),
             2 * widthRatio,
             2 * heightRatio
    };
    
    return new Buffer(BufferData::fromRectToImage(rect),
                      BufferConfiguration::_2_2);
}

void ScrollView::draw() {
    if (_needs_layout) layout();
        
    draw_subviews();
    
    UNPRIVATE(superview)->_frame_buffer->draw([&]{
        GL::setViewport(_frame_in_frame_buffer);
        Shader::uiTexture.use();
        _frame_buffer->getImage()->bind();
        _getBuffer()->draw();
        GL::unbindImage();
#if DRAW_DEBUG_FRAMES
        Shader::ui.use();
        Shader::ui.setUniformColor(ui::C::turquoise);
        Buffer::fullscreenOutline->draw();
#endif
    });
}


