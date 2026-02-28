//
//  Movable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Translatable.hpp"

using namespace gm;
using namespace scene;


const Matrix4& Translatable::translation_matrix() const {
    return _translation_matrix;
}

void Translatable::update_matrices() {
    Object::update_matrices();
    _translation_matrix =  Matrix4::transform::translation(_position);
}
