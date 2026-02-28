//
//  Walkable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Movable.hpp"

namespace scene {

    class Flyable : public Movable {

    public:

        enum Direction {
            Forward = 0b000001,
            Back    = 0b000010,
            Left    = 0b000100,
            Right   = 0b001000,
            Up      = 0b010000,
            Down    = 0b100000
        };

        using Movable::Movable;

        virtual const gm::Vector3& direction() const = 0;

        float flying_speed = 0.1f;

        void fly(Direction);

    };

}
