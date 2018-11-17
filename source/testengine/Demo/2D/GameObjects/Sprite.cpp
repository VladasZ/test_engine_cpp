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
#include "Window.hpp"
#include "GL.hpp"

Sprite::Sprite(Image* image) : _image(image) { }

Sprite::~Sprite() {
    if (_subsprites)
        delete _subsprites;
}
//
//BufferData* Sprite::getBufferData() {
//    
//    GLfloat* vertices;
//    
//    if (_subspriteIndex == -1) {
//        GLfloat vert[] = {
//            0,           0,            0.0f, 0.0f,
//            0,           _size.height, 0.0f, 1.0f,
//            _size.width, _size.height, 1.0f, 1.0f,
//            _size.width, 0,            1.0f, 0.0f
//        };
//        
//        vertices = vert;
//    }
//    else {
//        
//        Rect subFrame = _subsprites->at(_subspriteIndex);
//        
//        float widthRatio  = 1 / _image->size.width;
//        float heightRatio = 1 / _image->size.height;
//        
//        float x      = subFrame.origin.x    * widthRatio;
//        float y      = subFrame.origin.y    * heightRatio;
//        float width  = subFrame.size.width  * widthRatio;
//        float height = subFrame.size.height * heightRatio;
//        
//        GLfloat vert[] = {
//            0,           0,            x, y,
//            0,           _size.height, x, y + height,
//            _size.width, _size.height, x + width, y + height,
//            _size.width, 0,            x + width, y
//        };
//        
//        vertices = vert;
//    }
//    
//    static const GLushort indices[] = { 0, 1, 3, 2 };
//    
//    return new BufferData(vertices, sizeof(GLfloat) * 16,
//                          indices,  sizeof(indices));
//    
//}

void Sprite::draw() {
    /*  if (_neeedsBufferUpdate) {
        setupBuffer();
        _neeedsBufferUpdate = false;
    }
    _image->bind();
    Shader::sprite.use();

    mat4 transform = translate(mat4(), vec3(_position.x, _position.y, 0));
    transform = rotate(transform, rotation, vec3(0, 0, 1));
    transform = translate(transform, vec3(-_position.x, -_position.y, 0));
        
    Shader::sprite.setTransformMatrix(transform);
    Shader::sprite.setUniformPosition(_position.x - _size.width / 2, _position.y - _size.height / 2);
    buffer->draw();
    _image->unbind();*/
}

//const BufferConfiguration Sprite::bufferConfiguration() const {
//    return BufferConfiguration(2, 2);
//}

void Sprite::setPosition(const Point &position) {
    _position = position;
}

Point Sprite::position() {
    return _position;
}

void Sprite::setSize(const Size &size) {
    _size = size;
    _neeedsBufferUpdate = true;
}

Size Sprite::size() {
    return _size;
}

void Sprite::setSubsprites(const std::initializer_list<Rect> &subsprites) {
    _subsprites = new Array<Rect>(subsprites);
    setSubspriteIndex(0);
}

void Sprite::setSubspriteIndex(int index) {
    if (_subspriteIndex == index) return;
    _subspriteIndex = index;
    _neeedsBufferUpdate = true;
}

int Sprite::getSubspriteIndex() const {
    return _subspriteIndex;
}

