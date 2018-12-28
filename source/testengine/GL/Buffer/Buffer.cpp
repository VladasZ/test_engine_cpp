//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Debug.hpp"
#include "Screen.hpp"

Buffer::Buffer(BufferData* data, const BufferConfiguration& configuration) : data(data) {
    
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
    
    configuration.setPointers();
    GL(glEnableVertexAttribArray(0));
    GL(glBindVertexArray(0));
}

Buffer::Buffer(GLfloat* vert_data, GLuint vert_size, const BufferConfiguration& configuration)
:
Buffer(new BufferData(vert_data, vert_size), configuration) { }

Buffer::Buffer(GLfloat* vert_data, GLuint vert_size,
               GLushort* ind_data,  GLuint ind_size,
               const BufferConfiguration& configuration)
:
Buffer(new BufferData(vert_data, vert_size, ind_data, ind_size), configuration) { }

Buffer::~Buffer() {
    GL(glDeleteBuffers(1, &vertex_buffer_object));
    if (index_buffer_object != 0) GL(glDeleteBuffers(1, &index_buffer_object));
    GL(glDeleteVertexArrays(1, &vertex_array_object));
    delete data;
}

void Buffer::draw() const {
 
    GL(glBindVertexArray(vertex_array_object));
    
    if (data->ind_size == 0)
        GL(glDrawArrays(draw_mode, 0, static_cast<GLsizei>(vertices_count)));
    else
        GL(glDrawElements(draw_mode, static_cast<GLsizei>(indices_count), GL_UNSIGNED_SHORT, nullptr));
    
    GL(glBindVertexArray(0));
}

void Buffer::initialize() {

    static const ui::Rect fulscreen_rect { -1, -1,  2,  2 };
    static const ui::Rect almost_fulscreen_rect { -0.999f, -0.999f,  1.999f,  1.999f };

    fullscreen = new Buffer(BufferData::from_rect(fulscreen_rect), BufferConfiguration::_2);
    
    fullscreen_image = new Buffer(
		BufferData::from_rect_to_image(fulscreen_rect),
        BufferConfiguration::_2_2
    );

    auto outlineData = BufferData::from_rect(almost_fulscreen_rect);
    
    outlineData->setIndices({ 0, 1, 2, 3 });
    fullscreen_outline = new Buffer(outlineData, BufferConfiguration::_2);
    
    fullscreen_outline->draw_mode = GL_LINE_LOOP;
    
    window_size_changed();
}

void Buffer::window_size_changed() {

    if (root_ui_buffer != nullptr) delete root_ui_buffer;

    const auto height_ratio = Screen::display_resolution.height / Screen::size.height;

    const ui::Rect rect {
	   -1, 
	   -1 + 2 * (1 - height_ratio),
        2 * (Screen::display_resolution.width / Screen::size.width),
	    2 * height_ratio
    };

    root_ui_buffer = new Buffer(
		BufferData::from_rect_to_framebuffer(rect),
        BufferConfiguration::_2_2
    );
}
