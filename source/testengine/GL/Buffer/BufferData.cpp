//
//  BufferData.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <iostream>
using namespace std;


#include <cstring>

#include "BufferData.hpp"

static const std::vector<GLushort> rect_indices = { 0, 1, 3, 2 };

BufferData::BufferData(const std::vector<GLfloat>& vertices, const std::vector<GLushort>& indices)
    : vertices(vertices), indices(indices) { }

const char* BufferData::to_string(unsigned int new_line) const {
    static std::string string;
    string = "\n";

    for (size_t i = 0; i < vertices.size(); i++) {
        string += std::to_string(vertices[i]) + " ";
        if ((i + 1) % (new_line) == 0)
            string += "\n";
    }

    string += "\n";

    for (GLuint i = 0; i < indices.size(); i++) {
        string += std::to_string(indices[i]) + " ";
        if ((i + 1) % (new_line) == 0)
            string += "\n";
    }

    return string.c_str();
}

BufferData* BufferData::from_size(const Size& size) {
    const std::vector<GLfloat> vertices = {
        0,          0,
        0,          size.height,
        size.width, size.height,
        size.width, 0
    };
    return new BufferData(vertices, rect_indices);
}

BufferData* BufferData::from_rect(const Rect& rect) {
    const std::vector<GLfloat> vertices = {
        rect.origin.x,                   rect.origin.y,
        rect.origin.x,                   rect.size.height + rect.origin.y,
        rect.size.width + rect.origin.x, rect.size.height + rect.origin.y,
        rect.size.width + rect.origin.x, rect.origin.y
    };
    return new BufferData(vertices, rect_indices);
}

BufferData* BufferData::from_rect_to_image(const Rect& rect) {
    const std::vector<GLfloat> vertices = {
        rect.origin.x,                   rect.origin.y,                    0.0f,  1.0f, //|- |
        rect.origin.x,                   rect.size.height + rect.origin.y, 0.0f,  0.0f, //|_ |
        rect.size.width + rect.origin.x, rect.size.height + rect.origin.y, 1.0f,  0.0f, //| _|
        rect.size.width + rect.origin.x, rect.origin.y,                    1.0f,  1.0f  //| -|
    };
    return new BufferData(vertices, rect_indices);
}

BufferData* BufferData::from_rect_to_framebuffer(const Rect& rect) {
    const std::vector<GLfloat> vertices = {
        rect.origin.x,                   rect.origin.y,                    0.0f,  1.0f, //|- |
        rect.origin.x,                   rect.size.height + rect.origin.y, 0.0f,  0.0f, //| _|
        rect.size.width + rect.origin.x, rect.size.height + rect.origin.y, 1.0f,  0.0f, //| -|
        rect.size.width + rect.origin.x, rect.origin.y,                    1.0f,  1.0f  //| _|
    };
    return new BufferData(vertices, rect_indices);
}


