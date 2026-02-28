//
//  FabrikKinematicsModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "BoxModel.hpp"
#include "VectorModel.hpp"
#include "FabrikKinematics.hpp"

namespace scene {

class FabrikKinematicsModel : public BoxModel {

    gm::FabrikKinematics* _skeleton;

    std::vector<BoxModel*> _boxes;
    std::vector<VectorModel*> _vectors;

public:

    const float scale;

    FabrikKinematicsModel(gm::FabrikKinematics*, float scale = 1);

    gm::FabrikKinematics* skeleton() const;

    void reach_to(const gm::Vector3&);

    void update();

};

}
