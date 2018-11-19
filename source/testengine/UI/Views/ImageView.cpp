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
    
	if (_needsLayout) layout();

	if (_needsDraw) {
		_frameBuffer->draw([&] {
			_image->bind();
			if (_image->isMonochrome()) Shader::uiMonochrome.use();
			else                        Shader::uiTexture.use();
			GL::setViewport(_frameInFrameBuffer);
			Buffer::fullscreenImage->draw();
			_image->unbind();
#if DRAW_DEBUG_FRAMES
            Shader::ui.use();
            Shader::ui.setUniformColor(C::turquoise);
            Buffer::fullscreenOutline->draw();
#endif
		});
		_needsDraw = false;
	}

	drawSubviews();
}

Image* ImageView::getImage() const {
    return _image;
}

ImageView* ImageView::setImage(Image* image) {
    this->_image = image;
    return this;
}