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

Buffer::Buffer(BufferData* data, const BufferConfiguration& configuration) : data(data), draw_mode(GL_TRIANGLE_STRIP) {
    
    vertices_count = data->vert_size / (sizeof(float) * configuration.configuration[0]);
    
    GL(glGenVertexArrays(1, &vertex_array_object));
    GL(glBindVertexArray(vertex_array_object));
    
    GL(glGenBuffers(1, &vertex_buffer_object));
    GL(glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object));
    GL(glBufferData(GL_ARRAY_BUFFER, data->vert_size, data->vert_data, GL_STATIC_DRAW));

    if (data->ind_size != 0) {
        GL(glGenBuffers(1, &index_buffer_object));
        GL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object));
        GL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->ind_size, data->ind_data, GL_STATIC_DRAW));
        indices_count = data->ind_size / sizeof(GLushort);
    }
    
    configuration.set_pointers();
    GL(glEnableVertexAttribArray(0));
    GL(glBindVertexArray(0));
}

Buffer::Buffer(const GLfloat* vert_data,
               GLuint vert_size,
               const BufferConfiguration& configuration)
: Buffer(new BufferData(vert_data, vert_size), configuration) { }

Buffer::Buffer(const GLfloat* vert_data, GLuint vert_size,
               const GLushort* ind_data, GLuint ind_size,
               const BufferConfiguration& configuration)
: Buffer(new BufferData(vert_data, vert_size, ind_data, ind_size), configuration) { }

Buffer::Buffer(const std::vector<GLfloat>& vertices,
               const std::vector<GLushort>& indices,
               const BufferConfiguration& configuration)
: Buffer(vertices.data(), static_cast<GLuint>(vertices.size()), indices.data(), static_cast<GLuint>(indices.size()), configuration) { }

Buffer::Buffer(const scene::Mesh* mesh, const BufferConfiguration& configuration)
    : Buffer(reinterpret_cast<const GLfloat*>(mesh->vertices.data()),
             static_cast<GLuint>(mesh->vertices.size() * 3 * sizeof (Vector3::Float)),
             reinterpret_cast<const GLushort*>(mesh->indices.data()),
             static_cast<GLuint>(mesh->indices.size() * sizeof(GLushort)),
             configuration) { }

Buffer::~Buffer() {
    GL(glDeleteBuffers(1, &vertex_buffer_object));
    if (index_buffer_object != 0)
        GL(glDeleteBuffers(1, &index_buffer_object));
    GL(glDeleteVertexArrays(1, &vertex_array_object));
    delete data;
}

void Buffer::draw() const {

    GL(glBindVertexArray(vertex_array_object));
    
    if (data->ind_size == 0) {
        GL(glDrawArrays(draw_mode, 0, static_cast<GLsizei>(vertices_count)));
    } else {
        GL(glDrawElements(draw_mode, static_cast<GLsizei>(indices_count), GL_UNSIGNED_SHORT, nullptr));
    }
    
    GL(glBindVertexArray(0));
}

const char* Buffer::to_string(unsigned int new_line) const {
    static std::string string;
    string = "\n";
    for (GLuint i = 0; i < data->vert_size / sizeof(Vector3::Float); i++) {
        string += std::to_string(data->vert_data[i]) + " ";
        if ((i + 1) % (new_line) == 0)
            string += "\n";
    }
    return string.c_str();
}

void Buffer::initialize(const Size& display_resolution, const Size& window_size) {

    static const Rect fulscreen_rect { -1, -1,  2,  2 };
    static const Rect almost_fulscreen_rect { -0.999f, -0.999f,  1.999f,  1.999f };

    fullscreen = new Buffer(BufferData::from_rect(fulscreen_rect), BufferConfiguration::_2);
    
    fullscreen_image = new Buffer(BufferData::from_rect_to_image(fulscreen_rect), BufferConfiguration::_2_2);

    auto outline_data = BufferData::from_rect(almost_fulscreen_rect);
    
    outline_data->set_indices({ 0, 1, 2, 3 });
    fullscreen_outline = new Buffer(outline_data, BufferConfiguration::_2);
    
    fullscreen_outline->draw_mode = GL_LINE_LOOP;
    
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
