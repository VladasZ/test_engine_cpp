//
//  BufferData.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

 #include <cstring>

#include "BufferData.hpp"

static const GLushort indices[] = { 0, 1, 3, 2 };

BufferData::BufferData(const GLfloat* vertData, GLuint vertSize)
:
vertSize(vertSize)
{
    this->vertData = (GLfloat*)malloc(vertSize);
    memcpy(this->vertData, vertData, vertSize);
}

BufferData::BufferData(const GLfloat* vertData, GLuint vertSize,
                       const GLushort* indData, GLuint indSize)
:
vertSize(vertSize),
indSize(indSize)
{
    this->vertData = (GLfloat*)malloc(vertSize);
    memcpy(this->vertData, vertData, vertSize);
    
    this->indData = (GLushort*)malloc(indSize);
    memcpy(this->indData, indData, indSize);
}

BufferData* BufferData::fromSize(const Size& size) {
	const GLfloat data[] = {
		0,          0,
		0,          size.height,
		size.width, size.height,
		size.width, 0
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData* BufferData::fromRect(const Rect& rect) {
	GLfloat data[] = {
		rect.origin.x,                   rect.origin.y,
		rect.origin.x,                   rect.size.height + rect.origin.y,
		rect.size.width + rect.origin.x, rect.size.height + rect.origin.y,
		rect.size.width + rect.origin.x, rect.origin.y
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData* BufferData::fromRectToImage(const Rect& rect) {
	GLfloat data[] = {
		rect.origin.x,                   rect.origin.y,                    0.0f,  1.0f, //|_ |
		rect.origin.x,                   rect.size.height + rect.origin.y, 0.0f,  0.0f, //|- |
		rect.size.width + rect.origin.x, rect.size.height + rect.origin.y, 1.0f,  0.0f, //| -|
		rect.size.width + rect.origin.x, rect.origin.y,                    1.0f,  1.0f  //| _|
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData::~BufferData() {
    if (vertData != nullptr) free(vertData);
    if (indData  != nullptr) free(indData);
}
