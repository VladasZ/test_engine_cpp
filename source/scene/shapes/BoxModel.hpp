//
//  BoxModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Box.hpp"
#include "Model.hpp"

namespace scene {

class BoxModel : public Model {

public:

    gm::Box box;

    BoxModel(const gm::Box& = { });

};

}
