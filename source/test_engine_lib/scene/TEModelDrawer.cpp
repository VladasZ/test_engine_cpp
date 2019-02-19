//
//  TEModelDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Shader.hpp"
#include "Buffer.hpp"
#include "TexturedModel.hpp"
#include "TEModelDrawer.hpp"


TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;
    _buffer = new Buffer(model->mesh());
    _buffer->draw_mode = model->draw_mode();
}

TEModelDrawer::~TEModelDrawer() {

}

void TEModelDrawer::_draw() const {
    _buffer->bind();
    if (auto textured_model = dynamic_cast<const scene::TexturedModel*>(_model)) {
        textured_model->texture()->bind();
    } else if (_model->draw_mode() == scene::Model::DrawMode::Lines) {
        _buffer->shader()->set_uniform_color(Color::black);
    }
    _buffer->shader()->set_mvp_matrix(_model->mvp_matrix());
    _buffer->draw();
}
