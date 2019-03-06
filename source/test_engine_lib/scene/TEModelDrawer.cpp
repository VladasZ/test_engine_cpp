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


TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;

    auto mesh = model->mesh();

    std::vector<float> vertices { mesh->vertices_data(), mesh->vertices_data() + mesh->vertices_data_float_size() };

    auto conf   = gl::BufferConfiguration::_3_3_2;
    auto shader = Assets::shaders->textured3D;

    if (mesh->is_colored()) {
        conf   = gl::BufferConfiguration::_3_3_4;
        shader = Assets::shaders->diffuse_colored;
    } else if (mesh->is_plain()) {
        conf   = gl::BufferConfiguration::_3_3;
        shader = Assets::shaders->simple3D;
    }

    _buffer = new gl::Buffer(vertices, mesh->indices(), conf, shader);
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
    _buffer->shader()->set_model_matrix(_model->model_matrix());
    if (_model->_scene->_light_sources.size())
        _buffer->shader()->set_light_position(_model->_scene->_light_sources.front()->position());
    _buffer->draw();

}
