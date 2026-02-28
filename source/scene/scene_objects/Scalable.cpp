//
//  Scalable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/20/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Scalable.hpp"

using namespace gm;
using namespace scene;


const Vector3& Scalable::scale() const {
    return _scale;
}

void Scalable::set_scale(float scale) {
    _scale = { scale, scale, scale };
    _need_matrices_update = true;
}

void Scalable::set_scale(const Vector3& scale) {
    _scale = scale;
    _need_matrices_update = true;
}

const Matrix4& Scalable::model_matrix() const {
    return _model_matrix;
}

void Scalable::update_matrices() {
    Rotatable::update_matrices();
    _scale_matrix = Matrix4::transform::scale(_scale);
    _model_matrix = _translation_matrix * _rotation_matrix * _scale_matrix;
}
