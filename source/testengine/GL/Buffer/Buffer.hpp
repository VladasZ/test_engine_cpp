//
//  Buffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "NonCopyable.hpp"
#include "BufferData.hpp"
#include "BufferConfiguration.hpp"

class Buffer : public NonCopyable {
    
    BufferData* data;
    
    GLuint vertex_array_object  = 0;
    GLuint vertex_buffer_object = 0;
    GLuint index_buffer_object  = 0;
    
    unsigned int vertices_count = 0;
    unsigned int indices_count  = 0;

public:
    
    GLenum draw_mode = GL_TRIANGLE_STRIP;
    
    Buffer(BufferData* data, const BufferConfiguration& configuration);
    
    Buffer(GLfloat* vert_data, GLuint vert_size, const BufferConfiguration& configuration);
    
    Buffer(GLfloat* vert_data, GLuint vert_size,
           GLushort* ind_data, GLuint ind_size,
           const BufferConfiguration& configuration);

    ~Buffer();
        
    void draw() const;

    static void initialize();

    static void window_size_changed();

    static inline Buffer* fullscreen         = nullptr;
    static inline Buffer* fullscreen_image   = nullptr;
    static inline Buffer* fullscreen_outline = nullptr;
    static inline Buffer* root_ui_buffer     = nullptr;
};
