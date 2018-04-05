//
//  Sprite.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Sprite.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"
#include "Image.hpp"
#include "Window.hpp"


Sprite::Sprite(Image *image) : image(image) { }

BufferData * Sprite::getBufferData() {
    
    GLfloat vertices[] = {
        0,           0,            0.0f, 0.0f,
        0,           _size.height, 0.0f, 1.0f,
        _size.width, _size.height, 1.0f, 1.0f,
        _size.width, 0,            1.0f, 0.0f
    };
    
    GLushort indices[] = { 0, 1, 3, 2 };
    
    return new BufferData(vertices, sizeof(vertices),
                          indices,  sizeof(indices));
    
}

void Sprite::draw() {
    if (neeedsBufferUpdate) {
        setupBuffer();
        neeedsBufferUpdate = false;
    }
    image->bind();
    Shader::sprite.use();
    
    mat4 uiProjection = scale(mat4(), vec3(2 / Window::size.width, -(2 / Window::size.height), 1));
    uiProjection = translate(uiProjection, vec3(-Window::size.width / 2, - Window::size.height / 2, 0));
    
    uiProjection = translate(uiProjection, vec3(_position.x, _position.y, 0));
    uiProjection = rotate(uiProjection, rotation, vec3(0, 0, 1));
    uiProjection = translate(uiProjection, vec3(-_position.x, -_position.y, 0));
    
    Shader::sprite.setUITranslationMatrix(uiProjection);
    Shader::sprite.setUniformPosition(_position.x - _size.width / 2, _position.y - _size.height / 2);
    buffer->draw();
    image->unbind();
}

const BufferConfiguration Sprite::bufferConfiguration() const {
    return BufferConfiguration(2, 2);
}

void Sprite::setPosition(const Point &position) { _position = position; }
Point Sprite::position() { return _position; }

void Sprite::setSize(const Size &size) { _size = size; neeedsBufferUpdate = true; }
Size Sprite::size() { return _size; }

