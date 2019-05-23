//
//  TEModelDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Debug.hpp"
#include "Assets.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"
#include "ArrayUtils.hpp"
#include "PointLight.hpp"
#include "TEModelDrawer.hpp"
#include "BufferConfiguration.hpp"

using namespace gm;

TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;
    _buffer = new gl::Buffer(cu::array::convert<std::vector<float>>(model->mesh()->vertices()),
                             model->mesh()->indices(),
                             gl::BufferConfiguration::_3_3_2,
                             Assets::shaders->colored3D);
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

    _buffer->shader()->set_selected(_model->selected);
    _buffer->shader()->set_uniform_color(_model->color);
    _buffer->shader()->set_mvp_matrix(_model->mvp_matrix());

    _buffer->draw();

}
