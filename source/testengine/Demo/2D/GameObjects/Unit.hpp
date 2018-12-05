//
//  Unit.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Movable.hpp"

enum class UnitAnimation : int {
    Left,
    LeftMoved,
    Right,
    RightMoved
};

class Unit : public Movable {
    
    using Movable::velocity;
    
    float stepLength = 20;
    float distanceFromLastStep = 0;
    
public:
    
    using Movable::Movable;
    
    void update() override;
    
    void setVelocity(const ui::Point &velocity);
};
