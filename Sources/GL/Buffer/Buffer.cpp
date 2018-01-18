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
    
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);
    
    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, data->vertSize, data->vertData, GL_STATIC_DRAW);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          3 * sizeof(GLfloat),
                          NULL);
    
    if (data->indSize != 0) {
        glGenBuffers(1, &indexBufferObject);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indSize, data->indData, GL_STATIC_DRAW);
    }
    
    configuration.setPointers();
    
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
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
    glDeleteVertexArrays(1, &vertexArrayObject);
    glDeleteBuffers(1, &vertexBufferObject);
    if (indexBufferObject != 0) glDeleteBuffers(1, &indexBufferObject);
}

void Buffer::setPointers(int firstParam, int secondParam, int thirdParam) const {
    glBindVertexArray(vertexArrayObject);
    BufferConfiguration conf(firstParam, secondParam, thirdParam);
    conf.setPointers();
    glBindVertexArray(0);
}

void Buffer::setData(BufferData *data) {
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, data->vertSize, data->vertData, GL_STATIC_DRAW);
    
    if (data->indSize == 0) return;
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indSize, data->indData, GL_STATIC_DRAW);
}

void Buffer::draw() const {
 
    glBindVertexArray(vertexArrayObject);
    
    if (data->indSize == 0) {
        glDrawArrays(drawMode, 0, data->vertSize);
    }
    else {
        glDrawElements(drawMode, data->indSize, GL_UNSIGNED_SHORT, 0);
    }
    
    glBindVertexArray(0);
}
