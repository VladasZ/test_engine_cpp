//
//  ImageView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ImageView.hpp"
#include "Buffer.hpp"
#include "Image.hpp"
#include "Shader.hpp"
#include "BufferData.hpp"

ImageView::~ImageView() { }

BufferData * ImageView::getBufferData() {
    
    _absoluteFrame = calculateAbsoluteFrame();

    Rect frame = _absoluteFrame;
    
    static const GLfloat vertices[] = {
       -1.0f, -1.0f,  0.0f,  1.0f, //|_ |
       -1.0f,  1.0f,  0.0f,  0.0f, //|- |
        1.0f,  1.0f,  1.0f,  0.0f, //| -|
        1.0f, -1.0f,  1.0f,  1.0f  //| _|
    };
    
    static const GLushort indices[] = { 0, 1, 3, 2 };

    return new BufferData(vertices, sizeof(vertices),
                          indices,  sizeof(indices));
}

const BufferConfiguration ImageView::bufferConfiguration() const {
    return BufferConfiguration(2, 2);
}

void ImageView::draw() {
    
    if (_image == nullptr) { View::draw(); return; }
    if (!color.isTransparent()) View::draw();
       
    View::drawSubviews();
    
    _image->bind();
    if (_image->isMonochrome()) Shader::uiMonochrome.use();
    else                        Shader::uiTexture.use();
    _absoluteFrame.setViewport();
    buffer->draw();
    _image->unbind();
}

Image * ImageView::getImage() const {
    return _image;
}

ImageView * ImageView::setImage(Image *image) {
    this->_image = image;
    return this;
}
