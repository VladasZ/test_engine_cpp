//
//  BoneModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "BoxModel.hpp"
#include "BaseBone.hpp"
#include "VectorModel.hpp"

namespace scene {

class BoneModel : public BoxModel, public gm::BaseBone<BoneModel> {

private:

    VectorModel* vector = nullptr;

public:

    BoneModel(float length);

protected:

    void draw() override;

    void _setup() override;

};

}
