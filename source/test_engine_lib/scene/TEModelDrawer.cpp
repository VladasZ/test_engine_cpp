//
//  TEModelDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include                "Mesh.hpp"
#include               "Image.hpp"
#include               "Scene.hpp"
#include               "Debug.hpp"
#include              "Assets.hpp"
#include              "Shader.hpp"
#include              "Buffer.hpp"
#include          "PointLight.hpp"
#include       "TEModelDrawer.hpp"
#include "BufferConfiguration.hpp"

using namespace gm;

TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;

    auto vertices = model->mesh()->vertices();
    auto indices = model->mesh()->indices();

    auto vertices_pointer = reinterpret_cast<const float*>(vertices.data());

    using VerticesArrayType = std::remove_reference_t<decltype(vertices)>;
    static constexpr auto vertex_in_float_size = sizeof(VerticesArrayType::value_type) / sizeof(float);

    const std::vector<float> float_vertices = std::vector<float>(vertices_pointer,
                                                                 vertices_pointer + vertices.size() * vertex_in_float_size);

    auto conf   = gl::BufferConfiguration::_3_3_2;
    auto shader = Assets::shaders->textured3D;

    _buffer = new gl::Buffer(float_vertices, indices, conf, shader);
    _buffer->draw_mode = model->draw_mode();
}

TEModelDrawer::~TEModelDrawer() {

}

void TEModelDrawer::_draw() const {

    _buffer->bind();

    _buffer->shader()->use();

    if (_model->has_image())
        _model->image()->bind();

    else if (_model->draw_mode() == scene::Model::DrawMode::Lines)
        _buffer->shader()->set_uniform_color(Color::black);

    _buffer->shader()->set_mvp_matrix(_model->mvp_matrix());
    //_buffer->shader()->set_model_matrix(_model->model_matrix());


//    if (_model->_scene->_light_sources.size())
//        _buffer->shader()->set_light_position(_model->_scene->_light_sources.front()->position());


    _buffer->draw();

}
