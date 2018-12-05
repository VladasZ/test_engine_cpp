//
//  ImageView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ImageView.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"
#include "BufferData.hpp"
#include "FrameBuffer.hpp"
#include "Debug.hpp"

ImageView::~ImageView() { }

void ImageView::draw() {
    
	if (_needs_layout) layout();

	if (_need_draw) {
		_frame_buffer->draw([&] {
			_image->bind();
			if (_image->is_monochrome()) Shader::ui_monochrome.use();
			else                        Shader::ui_texture.use();
			GL::set_viewport(_frame_in_frame_buffer);
			Buffer::fullscreenImage->draw();
			_image->unbind();
#if DRAW_DEBUG_FRAMES
            Shader::ui.use();
            Shader::ui.set_uniform_color(ui::C::turquoise);
            Buffer::fullscreenOutline->draw();
#endif
		});
		_need_draw = false;
	}

	draw_subviews();
}

Image* ImageView::get_image() const {
    return _image;
}

ImageView* ImageView::set_image(Image* image) {
    this->_image = image;
    return this;
}
