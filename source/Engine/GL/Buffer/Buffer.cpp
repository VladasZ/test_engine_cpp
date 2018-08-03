//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Debug.hpp"
#include "Window.hpp"

Buffer::Buffer(BufferData* data, const BufferConfiguration &configuration) : data(data) {
    
    verticesCount = data->vertSize / (sizeof(float)* configuration.configuration[0]);
    
    GL(glGenVertexArrays(1, &vertexArrayObject));
    GL(glBindVertexArray(vertexArrayObject));
    
    GL(glGenBuffers(1, &vertexBufferObject));
    GL(glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject));
    GL(glBufferData(GL_ARRAY_BUFFER, data->vertSize, data->vertData, GL_STATIC_DRAW));

    if (data->indSize != 0) {
        GL(glGenBuffers(1, &indexBufferObject));
        GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject));
        GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indSize, data->indData, GL_STATIC_DRAW));
    }
    
    configuration.setPointers();
    GL(glEnableVertexAttribArray(0));
    GL(glBindVertexArray(0));
}

Buffer::Buffer(GLfloat* vertData, GLuint vertSize, const BufferConfiguration &configuration)
:
Buffer(new BufferData(vertData, vertSize), configuration) { }

Buffer::Buffer(GLfloat* vertData, GLuint vertSize,
               GLushort* indData,  GLuint indSize,
               const BufferConfiguration &configuration)
:
Buffer(new BufferData(vertData, vertSize, indData, indSize), configuration) { }

Buffer::~Buffer() {
    GL(glDeleteBuffers(1, &vertexBufferObject));
    if (indexBufferObject != 0) GL(glDeleteBuffers(1, &indexBufferObject));
    GL(glDeleteVertexArrays(1, &vertexArrayObject));
    delete data;
}

void Buffer::draw() const {
 
    GL(glBindVertexArray(vertexArrayObject));
    
    if (data->indSize == 0) {
        GL(glDrawArrays(drawMode, 0, verticesCount));
    }
    else {
        GL(glDrawElements(drawMode, verticesCount, GL_UNSIGNED_SHORT, 0));
    }
    
    GL(glBindVertexArray(0));
}

void Buffer::initialize() {

    static const Rect fulscreenRect { -1, -1,  2,  2 };

    fullscreen = new Buffer(BufferData::fromRect(fulscreenRect), BufferConfiguration::_2);

    fullscreenImage = new Buffer(
		BufferData::fromRectToImage(fulscreenRect),
        BufferConfiguration::_2_2
    );

    windowSizeChanged();
}

void Buffer::windowSizeChanged() {

    if (rootUIBuffer != nullptr) delete rootUIBuffer;

	const auto heightRatio = Window::screenResolution.height / Window::size.height;

    const Rect rect { 
	   -1, 
	   -1 + 2 * (1 - heightRatio),
	    2 * (Window::screenResolution.width / Window::size.width), 
	    2 * heightRatio
    };

    rootUIBuffer = new Buffer(
		BufferData::fromRectToImage(rect),
        BufferConfiguration::_2_2
    );
}
