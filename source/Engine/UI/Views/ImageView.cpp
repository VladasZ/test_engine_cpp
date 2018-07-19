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
#include "FrameBuffer.hpp"
#include "Debug.hpp"

ImageView::~ImageView() { }
//
//BufferData * ImageView::getBufferData() {
//    
//    _frameBufferFrame = _calculateFrameBufferFrame();
//    
//    static const GLfloat vertices[] = {
//       -1.0f, -1.0f,  0.0f,  1.0f, //|_ |
//       -1.0f,  1.0f,  0.0f,  0.0f, //|- |
//        1.0f,  1.0f,  1.0f,  0.0f, //| -|
//        1.0f, -1.0f,  1.0f,  1.0f  //| _|
//    };
//    
//    static const GLushort indices[] = { 0, 1, 3, 2 };
//
//    return new BufferData(vertices, sizeof(vertices),
//                          indices,  sizeof(indices));
//}

//const BufferConfiguration ImageView::bufferConfiguration() const {
//    return BufferConfiguration(2, 2);
//}

void ImageView::draw() {
    
    if (_image == nullptr) { View::draw(); return; }
    if (!color.isTransparent()) View::draw();
           
    _getFrameBuffer()->draw([&] {
        GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
        _image->bind();
        if (_image->isMonochrome()) Shader::uiMonochrome.use();
        else                        Shader::uiTexture.use();
        _frameBufferFrame.setViewport();
        Buffer::fullscreenImage->draw();
      //  buffer->draw();
        _image->unbind();
    });

    View::drawSubviews();
}

Image * ImageView::getImage() const {
    return _image;
}

ImageView * ImageView::setImage(Image *image) {
    this->_image = image;
    return this;
}
