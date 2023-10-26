
//
//  Shaders.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Rect.hpp"
#include "Vertex.hpp"
#include "Buffers.hpp"
#include "GLWrapper.hpp"
#include "BufferConfiguration.hpp"

using namespace gm;
using namespace gl;
using namespace std;

static constexpr Rect rect = { -1, -1, 2, 2 };
static constexpr array<Vertex::Index, 4> rect_indices = { 0, 1, 3, 2 };
static constexpr array<Vertex::Index, 4> indices      = { 0, 1, 2, 3 };


Buffers::Buffers() {

    static constexpr array<float, 8> fullscreen_vertices = {
            rect.origin.x,                   rect.origin.y,
            rect.origin.x,                   rect.size.height + rect.origin.y,
            rect.size.width + rect.origin.x, rect.size.height + rect.origin.y,
            rect.size.width + rect.origin.x, rect.origin.y
    };

    fullscreen = new gl::Buffer(gl::BufferConfiguration::_2, fullscreen_vertices, rect_indices);
    fullscreen->draw_mode = GL::DrawMode::TriangleStrip;

    static constexpr array<float, 16> image_vertices = {
            rect.origin.x,                   rect.origin.y,                    0.0f,  1.0f, //|- |
            rect.origin.x,                   rect.size.height + rect.origin.y, 0.0f,  0.0f, //|_ |
            rect.size.width + rect.origin.x, rect.size.height + rect.origin.y, 1.0f,  0.0f, //| _|
            rect.size.width + rect.origin.x, rect.origin.y,                    1.0f,  1.0f  //| -|
    };

    fullscreen_image = new gl::Buffer(gl::BufferConfiguration::_2_2, image_vertices, rect_indices);
    fullscreen_image->draw_mode = GL::DrawMode::TriangleStrip;

    static constexpr array<float, 8> outline_vertices = {
            rect.origin.x,                   rect.origin.y,
            rect.origin.x,                   rect.size.height + rect.origin.y,
            rect.size.width + rect.origin.x, rect.size.height + rect.origin.y,
            rect.size.width + rect.origin.x, rect.origin.y
    };

    fullscreen_outline = new gl::Buffer(gl::BufferConfiguration::_2, outline_vertices, indices);
    fullscreen_outline->draw_mode = GL::DrawMode::LineLoop;

}
