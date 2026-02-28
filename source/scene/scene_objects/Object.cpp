//
//  Object.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace gm;
using namespace scene;


Object::Object(const Vector3& position) : _position(position) {

}

Object::~Object() {

}

void Object::update_matrices() {
    if (_need_matrices_update) {
        on_moved();
        _need_matrices_update = false;
    }
}

void Object::set_needs_matrices_update() {
    _need_matrices_update = true;
}

void Object::update() {

}

const gm::Vector3& Object::position() const {
    return _position;
}

gm::Vector3& Object::edit_position() {
    _need_matrices_update = true;
    return _position;
}
