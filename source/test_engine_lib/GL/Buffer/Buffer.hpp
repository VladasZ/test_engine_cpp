//
//  Buffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Shader.hpp"

namespace scene {
class Mesh;
class ColoredMesh;
}

class Size;
class BufferData;
class BufferConfiguration;

class Buffer {
    
    BufferData* data;
    
    unsigned int vertex_array_object  = 0;
    unsigned int vertex_buffer_object = 0;
    unsigned int index_buffer_object  = 0;

    Shader* _shader;

private:

    void _initialize(BufferData* data, const BufferConfiguration& configuration, Shader* shader);

public:
    
    unsigned int draw_mode;

    Buffer(BufferData* data, const BufferConfiguration& configuration, Shader* shader);
    
    Buffer(const std::vector<float>& vertices,
           const std::vector<unsigned short>& indices,
           const BufferConfiguration& configuration,
           Shader* shader);

    Buffer(const scene::Mesh* mesh);

    ~Buffer();

    void bind() const;
    void draw() const;

    Shader* shader() const;

    const char* to_string(unsigned int new_line = 3) const;

    static void initialize(const Size& display_resolution, const Size& window_size);

    static void window_size_changed(const Size& display_resolution, const Size& window_size);

    static inline Buffer* fullscreen         = nullptr;
    static inline Buffer* fullscreen_image   = nullptr;
    static inline Buffer* fullscreen_outline = nullptr;
    static inline Buffer* root_ui_buffer     = nullptr;
};
