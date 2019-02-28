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
#include "BufferConfiguration.hpp"

void Buffer::_initialize(BufferData* data, const BufferConfiguration& configuration, Shader* shader) {

    _shader = shader;

    this->data = data;
    draw_mode = GL_TRIANGLES;

    GL(glGenVertexArrays(1, &vertex_array_object));
    GL(glBindVertexArray(vertex_array_object));

    GL(glGenBuffers(1, &vertex_buffer_object));
    GL(glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object));
    GL(glBufferData(GL_ARRAY_BUFFER,
                    static_cast<uint16_t>(data->vertices_data.size() * sizeof(GLfloat)),
                    data->vertices_data.data(),
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

Buffer::Buffer(BufferData* data, const BufferConfiguration& configuration, Shader* shader) {
    _initialize(data, configuration, shader);
}

Buffer::Buffer(const std::vector<float>& vertices,
               const std::vector<unsigned short>& indices,
               const BufferConfiguration& configuration,
               Shader* shader)
    : Buffer(new BufferData(vertices, indices), configuration, shader) { }

Buffer::Buffer(const scene::Mesh* mesh) {

    auto buffer_data = new BufferData { { mesh->vertices_data(), mesh->vertices_data() + mesh->vertices_data_size() }, mesh->indices() };

    if (mesh->is_textured()) {
        _initialize(buffer_data, BufferConfiguration::_3_3_2, Shader::textured3D);
        return;
    }

    if (mesh->is_plain()) {
        _initialize(buffer_data, BufferConfiguration::_3_3, Shader::simple3D);
        return;
    }

    if (mesh->is_colored()) {
        _initialize(buffer_data, BufferConfiguration::_3_3_4, Shader::colored3D);
        return;
    }
}

Buffer::~Buffer() {
    GL(glDeleteBuffers(1, &vertex_buffer_object));
    if (index_buffer_object != 0)
        GL(glDeleteBuffers(1, &index_buffer_object));
    GL(glDeleteVertexArrays(1, &vertex_array_object));
    delete data;
}

void Buffer::bind() const {
    _shader->use();
    GL(glBindVertexArray(vertex_array_object));
}

void Buffer::draw() const {
    if (data->indices.empty()) {
        GL(glDrawArrays(draw_mode, 0, static_cast<GLsizei>(data->vertices_data.size())));
    } else {
        GL(glDrawElements(draw_mode, static_cast<GLsizei>(data->indices.size()), GL_UNSIGNED_SHORT, nullptr));
    }
    GL(glBindVertexArray(0));
}

Shader* Buffer::shader() const {
    return _shader;
}

const char* Buffer::to_string(unsigned int new_line) const {
    return data->to_string(new_line);
}

void Buffer::initialize(const Size& display_resolution, const Size& window_size) {

    static const Rect fulscreen_rect { -1, -1,  2,  2 };
    static const Rect almost_fulscreen_rect { -0.999f, -0.999f,  1.999f,  1.999f };

    fullscreen = new Buffer(BufferData::from_rect(fulscreen_rect), BufferConfiguration::_2, Shader::ui);
    fullscreen->draw_mode = GL_TRIANGLE_STRIP;

    fullscreen_image = new Buffer(BufferData::from_rect_to_image(fulscreen_rect), BufferConfiguration::_2_2, Shader::ui_texture);
    fullscreen_image->draw_mode = GL_TRIANGLE_STRIP;
    
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

    root_ui_buffer = new Buffer(BufferData::from_rect_to_framebuffer(rect), BufferConfiguration::_2_2, Shader::ui_texture);
}
