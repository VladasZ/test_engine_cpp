//
//  PositionManipulator.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "XYZPack.hpp"
#include "BoxModel.hpp"
#include "VectorModel.hpp"

namespace scene {

class PositionManipulator : public BoxModel {

public:

    cu::XYZPack<VectorModel*> arrows = nullptr;
    cu::XYZPack<BoxModel*> planes = nullptr;
    BoxModel* box = nullptr;

    PositionManipulator();

    gm::Axis get_axis(Model* vector) const;
    gm::Axis get_plane(Model* plane) const;

};

}
