//
//  TEModelDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include            "GL.hpp"
#include         "Image.hpp"
#include         "Scene.hpp"
#include         "Debug.hpp"
#include        "Shader.hpp"
#include        "Buffer.hpp"
#include    "PointLight.hpp"
#include "TEModelDrawer.hpp"


TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;
    _buffer = new Buffer(model->mesh());
    _buffer->draw_mode = model->draw_mode();
}

TEModelDrawer::~TEModelDrawer() {

}

void TEModelDrawer::_draw() const {
    if (_model->is_transparent)
        GL(glDisable(GL_DEPTH_TEST));

    _buffer->bind();

    Shader::diffuse_colored->use();

//    if (_model->has_image())
//        _model->image()->bind();
//    else if (_model->draw_mode() == scene::Model::DrawMode::Lines)
//        _buffer->shader()->set_uniform_color(Color::black);

    Shader::diffuse_colored->set_mvp_matrix(_model->mvp_matrix());
    Shader::diffuse_colored->set_light_position(_model->_scene->_light_sources.front()->position());
    _buffer->draw();

    if (_model->is_transparent)
        GL(glEnable(GL_DEPTH_TEST));
}
