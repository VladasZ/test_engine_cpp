//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <string>

#include "GL.hpp"
#include "Log.hpp"
#include "Mesh.hpp"
#include "Debug.hpp"
#include "Buffer.hpp"
#include "BufferData.hpp"
#include "ColoredMesh.hpp"
#include "BufferConfiguration.hpp"

void Buffer::_initialize(BufferData* data, const BufferConfiguration& configuration) {

    this->data = data;
    draw_mode = GL_TRIANGLES;

    GL(glGenVertexArrays(1, &vertex_array_object));
    GL(glBindVertexArray(vertex_array_object));

    GL(glGenBuffers(1, &vertex_buffer_object));
    GL(glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object));
    GL(glBufferData(GL_ARRAY_BUFFER,
                    static_cast<uint16_t>(data->vertices.size() * sizeof(GLfloat)),
                    data->vertices.data(),
                    GL_STATIC_DRAW));

    if (!data->indices.empty()) {
        GL(glGenBuffers(1, &index_buffer_object));
        GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object));
        GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                        static_cast<uint16_t>(data->indices.size() * sizeof(GLushort)),
                        data->indices.data(),
                        GL_STATIC_DRAW));
    }

    configuration.set_pointers();
    GL(glEnableVertexAttribArray(0));
    GL(glBindVertexArray(0));
}

Buffer::Buffer(BufferData* data, const BufferConfiguration& configuration) {
    _initialize(data, configuration);
}

Buffer::Buffer(const std::vector<float>& vertices,
               const std::vector<unsigned short>& indices,
               const BufferConfiguration& configuration)
    : Buffer(new BufferData(vertices, indices), configuration) { }

Buffer::Buffer(const scene::Mesh* mesh) {

    if (auto colored_mesh = dynamic_cast<const scene::ColoredMesh*>(mesh)) {
        _initialize(new BufferData(colored_mesh->data, mesh->indices), BufferConfiguration::_3_3);
        return;
    }

    auto vertices =
            std::vector<float>(reinterpret_cast<const float*>(mesh->vertices.data()),
                               reinterpret_cast<const float*>(mesh->vertices.data()) + mesh->vertices.size() * 3);

    _initialize(new BufferData(vertices, mesh->indices), BufferConfiguration::_3);
}

Buffer::~Buffer() {
    GL(glDeleteBuffers(1, &vertex_buffer_object));
    if (index_buffer_object != 0)
        GL(glDeleteBuffers(1, &index_buffer_object));
    GL(glDeleteVertexArrays(1, &vertex_array_object));
    delete data;
}

void Buffer::draw() const {
    GL(glBindVertexArray(vertex_array_object));    
    if (data->indices.empty()) {
        GL(glDrawArrays(draw_mode, 0, static_cast<GLsizei>(data->vertices.size())));
    } else {
        GL(glDrawElements(draw_mode, static_cast<GLsizei>(data->indices.size()), GL_UNSIGNED_SHORT, nullptr));
    }
    GL(glBindVertexArray(0));
}

const char* Buffer::to_string(unsigned int new_line) const {
    return data->to_string(new_line);
}

void Buffer::initialize(const Size& display_resolution, const Size& window_size) {

    static const Rect fulscreen_rect { -1, -1,  2,  2 };
    static const Rect almost_fulscreen_rect { -0.999f, -0.999f,  1.999f,  1.999f };

    fullscreen = new Buffer(BufferData::from_rect(fulscreen_rect), BufferConfiguration::_2);
    fullscreen->draw_mode = GL_TRIANGLE_STRIP;

    fullscreen_image = new Buffer(BufferData::from_rect_to_image(fulscreen_rect), BufferConfiguration::_2_2);
    fullscreen_image->draw_mode = GL_TRIANGLE_STRIP;

//    auto outline_data = BufferData::from_rect(almost_fulscreen_rect);
    
//    outline_data->set_indices({ 0, 1, 2, 3 });
//    fullscreen_outline = new Buffer(outline_data, BufferConfiguration::_2);
    
//    fullscreen_outline->draw_mode = GL_LINE_LOOP;
    
    window_size_changed(display_resolution, window_size);
}

void Buffer::window_size_changed(const Size& display_resolution, const Size& window_size) {

    if (root_ui_buffer != nullptr)
        delete root_ui_buffer;

    const auto height_ratio = display_resolution.height / window_size.height;

    const Rect rect {
        -1,
        -1 + 2 * (1 - height_ratio),
             2 * (display_resolution.width / window_size.width),
             2 * height_ratio
    };

    root_ui_buffer = new Buffer(BufferData::from_rect_to_framebuffer(rect), BufferConfiguration::_2_2);
}