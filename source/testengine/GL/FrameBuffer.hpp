//
//  FrameBuffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <functional>

#include "DeprecatedImage.hpp"
#include "Rect.hpp"
#include "GL.hpp"

class FrameBuffer {

    GLuint _id;
    GLuint _rbo;
	ui::Size _size;
    DeprecatedImage* _image;

public:

    FrameBuffer(const ui::Size& size);
    ~FrameBuffer();

    FrameBuffer* bind();
    FrameBuffer* unbind();

	ui::Size get_size() const;
    FrameBuffer* set_size(const ui::Size& size);

    DeprecatedImage* get_image() const;

    FrameBuffer* draw(std::function<void()> closure);

    FrameBuffer* clear(const ui::Color& color = ui::C::clear);
};
