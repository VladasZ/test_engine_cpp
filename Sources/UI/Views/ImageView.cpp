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

ImageView::ImageView(Float x, Float y, Float width, Float height) : View(x, y, width, height) {
    
    setupBuffer();
}

ImageView::ImageView(Float width, Float height) : View(0, 0, width, height) {
    
}

BufferData ImageView::getBufferData() {
    
    GLfloat vertices[] = {
        frame.origin.x,                    frame.origin.y,                     0.0f, 0.0f,
        frame.origin.x,                    frame.size.height + frame.origin.y, 0.0f, 1.0f,
        frame.size.width + frame.origin.x, frame.size.height + frame.origin.y, 1.0f, 1.0f,
        frame.size.width + frame.origin.x, frame.origin.y,                     1.0f, 0.0f
    };
    
    GLushort indices[] = { 0, 1, 2, 3 };

    return BufferData(vertices, sizeof(vertices),
                      indices,  sizeof(indices));
}

void ImageView::setupBuffer() {
    
    buffer = new Buffer(getBufferData(), BufferConfiguration(2, 2));
}

void ImageView::draw() const {
    
    if (image == nullptr) {
        View::draw();
        return;
    }
    
    View::drawSubviews();
    
    image->bind();
    buffer->draw();
    image->unbind();
}

void ImageView::setImage(Image *image) {
    
    this->image = image;
}

