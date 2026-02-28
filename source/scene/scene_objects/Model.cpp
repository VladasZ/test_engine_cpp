//
//  Model.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"
#include "Scene.hpp"
#include "Model.hpp"
#include "Camera.hpp"
#include "SceneConfig.hpp"

using namespace gm;
using namespace scene;


Model::Drawer::~Drawer() {

}

Model::Model(Mesh* mesh, Image* image) : Selectable(mesh), _draw_mode(DrawMode::Triangles), _mesh(mesh), _image(image) {
    _drawer = config::drawer()->init_model_drawer(this);
}

Model::Model(Mesh* mesh, DrawMode draw_mode) : Selectable(mesh), _draw_mode(draw_mode), _mesh(mesh), _image(nullptr) {
    _drawer = config::drawer()->init_model_drawer(this);
}

Model::~Model() {
    remove_all_submodels();
#ifdef USING_BULLET3D
    if (_rigid_body) delete _rigid_body;
#endif
    delete _drawer;
    delete _mesh;
}

Mesh* Model::mesh() const {
    return _mesh;
}

Model::DrawMode Model::draw_mode() const {
    return _draw_mode;
}

gm::Vector3& Model::edit_position() {
    _new_position = true;
    return Object::edit_position();
}

void Model::update() {
    if (_rigid_body != nullptr) {
        if (_new_position) {
            _rigid_body->set_position(_position);
            _new_position = false;
        }
        else {
            _rigid_body->update();
            _position = _rigid_body->position();
        }
        auto& quat = _rigid_body->rotation();
        set_rotation({ quat.x, quat.z, quat.y, -quat.w });
        _need_matrices_update = true;
    }
}

void Model::draw() {
    if (is_hidden) {
        return;
    }
    if (_need_matrices_update) {
        for (auto submodel : _submodels) {
            submodel->_need_matrices_update = true;
        }
        update_matrices();
    }
    _drawer->_draw();
    for (auto submodel : _submodels) {
        submodel->draw();
    }
}

void Model::draw_normals() {
    if (_need_matrices_update) {
        update_matrices();
    }
//    for (auto ver : mesh()->vertices()) {
//        _scene->_dummy_vector->edit_position() = _model_matrix * ver.position;
//        _scene->_dummy_vector->look_at(_model_matrix.multiply_by_normal(ver.normal));
//        _scene->_dummy_vector->draw();
//    }
}

void Model::add_bounding_box() {
    _scene->add_box(_position, bounding_box);
}

bool Model::has_image() const {
    return _image != nullptr;
}

Image* Model::image() const {
    return _image;
}

Model* Model::supermodel() const {
    return _supermodel;
}

void Model::add_submodel(Model* model) {
    _submodels.push_back(model);
    model->_supermodel = this;
    model->_scene = _scene;
    model->_setup();
}

const std::vector<Model*>& Model::submodels() const {
    return _submodels;
}

void Model::remove_all_submodels() {
    for (auto submodel : _submodels) {
        delete submodel;
    }
    _submodels.clear();
}

const Matrix4& Model::mvp_matrix() const {
    return _mvp_matrix;
}

Model* Model::intersecting_ray(const gm::Ray& ray) {
    if (intersects_ray(ray)) {
        return this;
    }
    for (auto submodel : _submodels) {
        if (auto intersecting = submodel->intersecting_ray(ray)) {
            return intersecting;
        }
    }
    return nullptr;
}

void Model::deselect() {
    is_selected = false;
    for (auto submodel : _submodels) {
        submodel->deselect();
    }
}

gm::Vector3 Model::absolute_position() const {
    if (_supermodel == nullptr) return _position;
    return _position + _supermodel->position();
}

void Model::_setup() {
    for (auto submodel : _submodels) {
        submodel->_scene = _scene;
        if (!respects_depth_buffer) {
            submodel->respects_depth_buffer = false;
        }
    }
}

RigidBody* Model::rigid_body() {
    return _rigid_body;
}

void Model::add_rigid_body(float size, float mass, RigidBody::Shape shape) {
#ifdef USING_BULLET3D
    _rigid_body = new RigidBody(_position, size, mass, shape);
#endif
}

void Model::update_matrices() {
    Scalable::update_matrices();
    if (_supermodel) {
        _model_matrix = _supermodel->_model_matrix * _model_matrix;
    }
    _mvp_matrix = _scene->camera->view_projection_matrix() * _model_matrix;
}
