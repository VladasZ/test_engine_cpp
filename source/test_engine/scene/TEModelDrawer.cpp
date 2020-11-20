//
//  TEModelDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Assets.hpp"
#include "Shader.hpp"
#include "Buffer.hpp"
#include "GLWrapper.hpp"
#include "PointLight.hpp"
#include "TEModelDrawer.hpp"
#include "BufferConfiguration.hpp"

using namespace cu;
using namespace gm;
using namespace gl;


TEModelDrawer::TEModelDrawer(scene::Model* model) {
    _model = model;
    _buffer = new gl::Buffer(gl::BufferConfiguration::_3_3_2, model->mesh()->vertices(), model->mesh()->indices());
    _buffer->draw_mode = model->draw_mode();
}

TEModelDrawer::~TEModelDrawer() {
    delete _buffer;
}

void TEModelDrawer::_draw() const {

	gl::Shader* shader = Assets::shaders->colored3D;

	if (_model->has_image()) {
		shader = Assets::shaders->textured3D;
    }
	else if (!_model->respects_depth_buffer) {
	    shader = Assets::shaders->simple3D;
	}

    shader->use();

    if (_model->has_image()) {
        _model->image()->bind();
    }
    else if (_model->draw_mode() == scene::Model::DrawMode::Lines) {
        shader->set_color(Color::black);
    }

	shader->set_selected(_model->is_selected);
	shader->set_color(_model->color);
	shader->set_mvp_matrix(_model->mvp_matrix());

	if (!_model->respects_depth_buffer) {
	    GL::disable_depth_test();
	}

    _buffer->draw();

    if (!_model->respects_depth_buffer) {
        GL::enable_depth_test();
    }
}
