//
//  Mesh.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Mesh.hpp"

Mesh::~Mesh() {
    if (_buffer)
        delete _buffer;
}

void Mesh::_createBuffer() {
    if (_buffer)
        return;
    
#if USE_COLORED_MESH
    _buffer = new Buffer((GLfloat*)coloredVertices.data(), (GLuint)coloredVertices.bytes_size(),
                         (GLushort*)indices.data(), (GLuint)indices.bytes_size(),
                         BufferConfiguration::_3_4);
    
#else
    _buffer = new Buffer((GLfloat*)vertices.data(), (GLuint)vertices.bytes_size(),
                         (GLushort*)indices.data(), (GLuint)indices.bytes_size(),
                         BufferConfiguration::_3);
#endif
    
    _buffer->drawMode = GL_TRIANGLES;
}

void Mesh::draw() {
    if (!_buffer)
        _createBuffer();
    _buffer->draw();
}
