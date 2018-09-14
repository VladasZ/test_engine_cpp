//
//  Polygon.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Polygon.hpp"

Polygon::~Polygon() {
    if (_buffer)
        delete _buffer;
}

void Polygon::_createBuffer() {
    if (_buffer)
        return;
    _buffer = new Buffer((GLfloat*)vertices.data(), (GLuint)vertices.bytes_size(),
                         (GLushort*)indices.data(), (GLuint)indices.bytes_size(),
                         BufferConfiguration::_3);
}

void Polygon::draw() {
    if (!_buffer)
        _createBuffer();
    _buffer->draw();
}
