//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Debug.hpp"

Buffer::Buffer(BufferData *data, const BufferConfiguration &configuration) : data(data) {
    
    GL(glGenVertexArrays(1, &vertexArrayObject));
    GL(glBindVertexArray(vertexArrayObject));
    
    GL(glGenBuffers(1, &vertexBufferObject));
    GL(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject));
    GL(glBufferData(GL_ARRAY_BUFFER, data->vertSize, data->vertData, GL_STATIC_DRAW));
    GL(glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          3 * sizeof(GLfloat),
                          NULL));
    
    if (data->indSize != 0) {
        GL(glGenBuffers(1, &indexBufferObject));
        GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject));
        GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indSize, data->indData, GL_STATIC_DRAW));
    }
    
    configuration.setPointers();
    
    GL(glEnableVertexAttribArray(0));
    GL(glBindVertexArray(0));
}

Buffer::Buffer(GLfloat *vertData, GLuint vertSize, const BufferConfiguration &configuration)
:
Buffer(new BufferData(vertData, vertSize), configuration) { }

Buffer::Buffer(GLfloat *vertData, GLuint vertSize,
               GLushort *indData,  GLuint indSize,
               const BufferConfiguration &configuration)
:
Buffer(new BufferData(vertData, vertSize, indData, indSize), configuration) { }

Buffer::~Buffer() {
    GL(glDeleteVertexArrays(1, &vertexArrayObject));
    GL(glDeleteBuffers(1, &vertexBufferObject)); // Potential crash
    if (indexBufferObject != 0) glDeleteBuffers(1, &indexBufferObject);
    delete data;
}

void Buffer::setPointers(int firstParam, int secondParam, int thirdParam) const {
    GL(glBindVertexArray(vertexArrayObject));
    BufferConfiguration conf(firstParam, secondParam, thirdParam);
    conf.setPointers();
    GL(glBindVertexArray(0));
}

void Buffer::setData(BufferData *data) {
    delete this->data;
    this->data = data;
    GL(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject));
    GL(glBufferData(GL_ARRAY_BUFFER, data->vertSize, data->vertData, GL_STATIC_DRAW));
    
    if (data->indSize == 0) return;
    
    GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject));
    GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indSize, data->indData, GL_STATIC_DRAW));
}

void Buffer::draw() const {
 
    GL(glBindVertexArray(vertexArrayObject));
    
    if (data->indSize == 0) {
        GL(glDrawArrays(drawMode, 0, data->vertSize));
    }
    else {
        GL(glDrawElements(drawMode, data->indSize, GL_UNSIGNED_SHORT, 0));
    }
    
    GL(glBindVertexArray(0));
}
