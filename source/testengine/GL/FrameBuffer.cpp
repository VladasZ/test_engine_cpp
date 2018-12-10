//
//  FrameBuffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "FrameBuffer.hpp"
#include "Image.hpp"
#include "Debug.hpp"

FrameBuffer::FrameBuffer(const ui::Size& size) : _size(size) {

    GL(glGenFramebuffers(1, &_id));
    GL(glBindFramebuffer(GL_FRAMEBUFFER, _id));

    _image = new Image(size);
    _image->bind();

    GL(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _image->_get_GL_id(), 0));

    GL(glGenRenderbuffers(1, &_rbo));
    GL(glBindRenderbuffer(GL_RENDERBUFFER, _rbo));
    GL(glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, (GLsizei)size.width, (GLsizei)size.height));
    GL(glBindRenderbuffer(GL_RENDERBUFFER, 0));

    GL(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _rbo));

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        Error("ERROR::FRAMEBUFFER:: Framebuffer is not complete!");
    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));

    clear();
    
    unbind();
}

FrameBuffer::~FrameBuffer() {
    unbind();
    _image->unbind();
    delete _image;
    glDeleteRenderbuffers(1, &_rbo);
    glDeleteFramebuffers(1, &_id);
}

FrameBuffer* FrameBuffer::bind() {
    GL(glBindFramebuffer(GL_FRAMEBUFFER, _id));
    return this;
}

FrameBuffer* FrameBuffer::unbind() {
    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    return this;
}

ui::Size FrameBuffer::get_size() const {
    return _size;
}

FrameBuffer* FrameBuffer::set_size(const ui::Size& size) {
    throw "Not implemented";
    _size = size;
    return this;
}

Image* FrameBuffer::get_image() const {
    return _image;
}

FrameBuffer* FrameBuffer::draw(std::function<void()> closure) {
    bind();
    glViewport(0, 0, (GLsizei)_size.width, (GLsizei)_size.height);
    closure();
    unbind();
    return this;
}

FrameBuffer* FrameBuffer::clear(const ui::Color& color) {
    bind();
    GL::set_clear_color(color);
    glViewport(0, 0, (GLsizei)_size.width, (GLsizei)_size.height);
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    unbind();
    return this;
}
