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
    
	if (_needs_layout) 
		layout();

	if (_needs_draw) {
		_image->draw_in_rect(_absolute_frame);
		_needs_draw = false;
	}

	draw_subviews();
}

DeprecatedImage* ImageView::image() const {
    return _image;
}

ImageView* ImageView::set_image(DeprecatedImage* image) {
    this->_image = image;
    return this;
}
