//
//  TEModelDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Shader.hpp"
#include "Buffer.hpp"
#include "TEModelDrawer.hpp"


TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;
    _buffer = new Buffer(model->mesh());
}

TEModelDrawer::~TEModelDrawer() { }

void TEModelDrawer::_draw() const {
    Shader::colored3D.use();
    Shader::colored3D.set_mvp_matrix(_model->mvp_matrix());
    _buffer->draw();
}
