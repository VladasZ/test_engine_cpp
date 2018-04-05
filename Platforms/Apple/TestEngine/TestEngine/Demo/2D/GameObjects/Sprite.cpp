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
#include "GL.hpp"

ostream &operator<<(ostream &os, mat4 const &mat) {
    return os << "\n"_s + mat[0][0] + " " + mat[0][1] + " " + mat[0][2] + " " + mat[0][3] + "\n" +
                          mat[1][0] + " " + mat[1][1] + " " + mat[1][2] + " " + mat[1][3] + "\n" +
                          mat[2][0] + " " + mat[2][1] + " " + mat[2][2] + " " + mat[2][3] + "\n" +
                          mat[3][0] + " " + mat[3][1] + " " + mat[3][2] + " " + mat[3][3] + "\n";
}


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

    mat4 transform = translate(mat4(), vec3(_position.x, _position.y, 0));
    transform = rotate(transform, rotation, vec3(0, 0, 1));
    transform = translate(transform, vec3(-_position.x, -_position.y, 0));
        
    Shader::sprite.setTransformMatrix(transform);
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

