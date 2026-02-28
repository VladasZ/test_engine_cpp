//
//  Rotatable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Rotatable.hpp"

using namespace gm;
using namespace scene;

void Rotatable::look_at(const Vector3& target) {
    _rotation_matrix = Matrix4::transform::model_look_at(target);
    _need_matrices_update = true;
    _ignore_quat = true;
}

const Vector4& Rotatable::rotation() const {
    return _rotation;
}

void Rotatable::set_rotation(const Vector4& rotation) {
    _rotation = rotation;
    _need_matrices_update = true;
    _ignore_quat = false;
}

void Rotatable::update_matrices() {
    Translatable::update_matrices();
    if (_ignore_quat) { return; }
    _rotation_matrix = Matrix4::transform::quaternion_rotation(_rotation);
}
