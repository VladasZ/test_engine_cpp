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

void Mesh::_create_buffer() {
    if (_buffer)
        return;
    
#if USE_COLORED_MESH
    _buffer = new Buffer((GLfloat*)colored_vertices.data(), (GLuint)colored_vertices.bytes_size(),
                         (GLushort*)indices.data(), (GLuint)indices.bytes_size(),
                         BufferConfiguration::_3_4);
    
#else
    _buffer = new Buffer((GLfloat*)vertices.data(), (GLuint)vertices.bytes_size(),
                         (GLushort*)indices.data(), (GLuint)indices.bytes_size(),
                         BufferConfiguration::_3);
#endif
    
    _buffer->draw_mode = GL_TRIANGLES;
}

void Mesh::draw() {
    if (!_buffer)
        _create_buffer();
    _buffer->draw();
}
