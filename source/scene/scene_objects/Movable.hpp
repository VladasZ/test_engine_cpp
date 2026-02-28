//
//  Movable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Object.hpp"
#include "Matrix4.hpp"

namespace scene {

    class Movable : public Object {

    public:

        using Object::Object;

        gm::Vector3 velocity;

        void stop();

        void update() override;

    };

}
