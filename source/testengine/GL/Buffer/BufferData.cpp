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

BufferData::BufferData(const GLfloat* vert_data, GLuint vert_size)
:
vert_size(vert_size)
{
    this->vert_data = (GLfloat*)malloc(vert_size);
    memcpy(this->vert_data, vert_data, vert_size);
}

BufferData::BufferData(const GLfloat* vert_data, GLuint vert_size,
                       const GLushort* ind_data, GLuint ind_size)
:
vert_size(vert_size),
ind_size(ind_size)
{
    this->vert_data = (GLfloat*)malloc(vert_size);
    memcpy(this->vert_data, vert_data, vert_size);
    
    this->ind_data = (GLushort*)malloc(ind_size);
    memcpy(this->ind_data, ind_data, ind_size);
}

BufferData* BufferData::setIndices(const Array<GLushort>& indices) {
    if (ind_data) free(ind_data);
    ind_size = (GLuint)(indices.size() * sizeof(GLushort));
    ind_data = (GLushort *)malloc(ind_size);
    memcpy(this->ind_data, indices.data(), ind_size);
    return this;
}

BufferData* BufferData::from_size(const ui::Size& size) {
	const GLfloat data[] = {
		0,          0,
		0,          size.height,
		size.width, size.height,
		size.width, 0
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData* BufferData::from_rect(const ui::Rect& rect) {
	GLfloat data[] = {
		rect.origin.x,                   rect.origin.y,
		rect.origin.x,                   rect.size.height + rect.origin.y,
		rect.size.width + rect.origin.x, rect.size.height + rect.origin.y,
		rect.size.width + rect.origin.x, rect.origin.y
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData* BufferData::from_rect_to_image(const ui::Rect& rect) {
	GLfloat data[] = {
        rect.origin.x,                   rect.origin.y,                    0.0f,  1.0f, //|- |
        rect.origin.x,                   rect.size.height + rect.origin.y, 0.0f,  0.0f, //|_ |
        rect.size.width + rect.origin.x, rect.size.height + rect.origin.y, 1.0f,  0.0f, //| _|
        rect.size.width + rect.origin.x, rect.origin.y,                    1.0f,  1.0f  //| -|
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData* BufferData::from_rect_to_framebuffer(const ui::Rect& rect) {
	GLfloat data[] = {
		rect.origin.x,                   rect.origin.y,                    0.0f,  1.0f, //|- |
		rect.origin.x,                   rect.size.height + rect.origin.y, 0.0f,  0.0f, //| _|
		rect.size.width + rect.origin.x, rect.size.height + rect.origin.y, 1.0f,  0.0f, //| -|
		rect.size.width + rect.origin.x, rect.origin.y,                    1.0f,  1.0f  //| _|
	};

	return new BufferData(data, sizeof(data), indices, sizeof(indices));
}

BufferData::~BufferData() {
    if (vert_data) free(vert_data);
    if (ind_data ) free(ind_data);
}
