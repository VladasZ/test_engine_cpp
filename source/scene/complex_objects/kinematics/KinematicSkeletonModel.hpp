//
//  KinematicSkeletonModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "BoxModel.hpp"
#include "VectorModel.hpp"
#include "ReachingBone.hpp"

namespace scene {

class KinematicSkeletonModel : public BoxModel {

    std::vector<gm::ReachingBone*> bones;

    std::vector<BoxModel*> _boxes;
    std::vector<VectorModel*> _vectors;

public:

    const float scale;

    KinematicSkeletonModel(float scale = 1);

    void add_bone(gm::ReachingBone*);

    void update();

protected:

    void _create_models_for_bone(gm::ReachingBone*);

};

}
