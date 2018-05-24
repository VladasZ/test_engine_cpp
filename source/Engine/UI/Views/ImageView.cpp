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
    

    GLfloat vertices[] = {
        frame.origin.x,                    frame.origin.y,                     0.0f, 0.0f,
        frame.origin.x,                    frame.size.height + frame.origin.y, 0.0f, 1.0f,
        frame.size.width + frame.origin.x, frame.size.height + frame.origin.y, 1.0f, 1.0f,
        frame.size.width + frame.origin.x, frame.origin.y,                     1.0f, 0.0f
    };
    
    GLushort indices[] = { 0, 1, 3, 2 };

    return new BufferData(vertices, sizeof(vertices),
                          indices,  sizeof(indices));
}

const BufferConfiguration ImageView::bufferConfiguration() const {
    return BufferConfiguration(2, 2);
}

void ImageView::draw() {
    
    if (image == nullptr) { View::draw(); return; }
    if (!color.isTransparent()) View::draw();
        
    View::drawSubviews();
    
    image->bind();
    if (image->isMonochrome()) Shader::uiMonochrome.use();
    else                       Shader::uiTexture.use();
    buffer->draw();
    image->unbind();
}
