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

    glGenFramebuffers(1, &_id);
    glBindFramebuffer(GL_FRAMEBUFFER, _id);

    _image = new Image(size);
    _image->bind();

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _image->_get_GL_id(), 0);

    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1000, 800);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    unbind();
}

FrameBuffer * FrameBuffer::bind() {
    GL(glBindFramebuffer(GL_FRAMEBUFFER, _id));
    return this;
}

FrameBuffer * FrameBuffer::unbind() {
    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    return this;
}

Rect FrameBuffer::getSize() const {
    return _size;
}

FrameBuffer * FrameBuffer::setSize(const Size& size) {
    throw "Not implemented";
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
    unbind();
    return this;
}
