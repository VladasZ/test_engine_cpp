//
//  SphereModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

namespace scene {

class SphereModel : public Model {

public:

    const float radius;

    SphereModel(float radius = 1.0f);

};

}
