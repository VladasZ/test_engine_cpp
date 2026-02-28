//
//  KinematicSkeletonModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "VectorModel.hpp"
#include "KinematicSkeletonModel.hpp"

using namespace gm;
using namespace scene;

static const auto joint_size = 0.18f;

KinematicSkeletonModel::KinematicSkeletonModel(float scale) : BoxModel(Box(joint_size * scale)), scale(scale) {
//    for ([[maybe_unused]] auto bone : _skeleton->bones) {
//
//        auto vector = new VectorModel();
//        add_submodel(vector);
//        vector->selectable = false;
//
//        auto box = new BoxModel(Box(joint_size * scale));
//        add_submodel(box);
//
//        _vectors.push_back(vector);
//        _boxes.push_back(box);
//    }
//
//    update();
}

void KinematicSkeletonModel::add_bone(gm::ReachingBone*) {

}

void KinematicSkeletonModel::update() {
    for (size_t i = 0; i < bones.size(); i++) {
        auto _bone = bones[i];
        auto vector = _vectors[i];
        auto _box = _boxes[i];
        vector->visualize_line_segment(_bone->line_segment(), scale);
		_box->edit_position() = _bone->end();
    }
}

void KinematicSkeletonModel::_create_models_for_bone(gm::ReachingBone*) {

}
