//
//  FrameBuffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <functional>

#include "Rect.hpp"
#include "GL.hpp"

class Image;

class FrameBuffer {

    GLuint _id;
    GLuint _rbo;
    Size _size;
    Image* _image;

public:

    FrameBuffer(const Size& size);
    ~FrameBuffer();

    FrameBuffer* bind();
    FrameBuffer* unbind();

    Rect getSize() const;
    FrameBuffer* setSize(const Size& size);

    Image* getImage() const;

    FrameBuffer* draw(std::function<void()> closure);

    FrameBuffer* clear();
};
