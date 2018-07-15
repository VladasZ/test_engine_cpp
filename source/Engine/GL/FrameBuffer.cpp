//
//  FrameBuffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "FrameBuffer.hpp"
#include "Image.hpp"
#include "Debug.hpp"

FrameBuffer::FrameBuffer(const Size& size) : _size(size) {
    GL(glGenFramebuffers(1, &_id));
    GL(glBindFramebuffer(GL_FRAMEBUFFER, _id));

    _image = new Image(_size);
    _image->bind();

    GL(glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, _image->_get_GL_id(), 0));

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        unbind();
        throw "Failed to initialize framebuffer";
    }

    unbind();
}

FrameBuffer * FrameBuffer::bind() {
    GL(glBindFramebuffer(GL_FRAMEBUFFER, _id));
  //  _image->bind();
 //   GL(glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, _image->_id, 0));
    return this;
}

FrameBuffer * FrameBuffer::unbind() {
    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    _image->unbind();
    return this;
}

Rect FrameBuffer::getSize() const {
    return _size;
}

FrameBuffer * FrameBuffer::setSize(const Size& size) {
    _size = size;
    return this;
}

Image * FrameBuffer::getImage() const {
    return _image;
}

FrameBuffer * FrameBuffer::draw(std::function<void()> closure) {
    bind();
    glViewport(0, 0, _size.width, _size.height);
    closure();
//    unbind();
    return this;
}
