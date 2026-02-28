//
//  BoneModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Scene.hpp"
#include "BoneModel.hpp"

using namespace gm;
using namespace scene;

BoneModel::BoneModel(float length) : BoxModel(0.01f), BaseBone(length) {
    vector = new VectorModel();
    add_submodel(vector);
}

void BoneModel::draw() {
    vector->visualize_line_segment(line_segment(), 0.1f);
    Model::draw();
}

void BoneModel::_setup() {
    Model::_setup();

    if (!is_root()) {
        return;
    }
    iterate_childred([&](BoneModel* child) {
        add_submodel(child);
    });
}
