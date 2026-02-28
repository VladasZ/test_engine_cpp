//
//  FabrikKinematicsModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "VectorModel.hpp"
#include "FabrikKinematicsModel.hpp"

using namespace gm;
using namespace scene;

static const auto joint_size = 0.18f;

FabrikKinematicsModel::FabrikKinematicsModel(FabrikKinematics* skeleton, float scale) : BoxModel(Box(joint_size * scale)), _skeleton(skeleton), scale(scale) {
    for (auto _bone [[maybe_unused]] : _skeleton->bones) {

        auto vector = new VectorModel();
        add_submodel(vector);
        vector->selectable = false;

        auto _box = new BoxModel(Box(joint_size * scale));
        add_submodel(_box);

        _vectors.push_back(vector);
        _boxes.push_back(_box);
    }

    update();
}

gm::FabrikKinematics* FabrikKinematicsModel::skeleton() const {
    return _skeleton;
}

void FabrikKinematicsModel::reach_to(const gm::Vector3& target) {
    _skeleton->reach_to(target);
    update();
}

void FabrikKinematicsModel::update() {
    for (size_t i = 0; i < _skeleton->bones.size(); i++) {
        auto bone = _skeleton->bones[i];
        auto vector = _vectors[i];
        auto _box = _boxes[i];
        vector->visualize_line_segment(bone->line_segment(), scale);
		_box->edit_position() = bone->end();
    }
}
