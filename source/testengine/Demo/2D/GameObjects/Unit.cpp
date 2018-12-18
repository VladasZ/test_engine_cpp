//
//  Unit.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <math.h>
#include <algorithm>

#include "Unit.hpp"

using namespace std;

void Unit::update() {
    
    float oldX = abs(_position.x);
    Movable::update();
    float newX = abs(_position.x);
    distanceFromLastStep += max(oldX, newX) - min(oldX, newX);
    if (distanceFromLastStep < stepLength) return;
    
    Direction direction = velocity.directionX();

    if (direction == Direction::Left) {
        if (getSubspriteIndex() == static_cast<int>(UnitAnimation::Left)) {
            setSubspriteIndex(static_cast<int>(UnitAnimation::LeftMoved));
        }
        else {
            setSubspriteIndex(static_cast<int>(UnitAnimation::Left));
        }
    }
    else {
        if (getSubspriteIndex() == static_cast<int>(UnitAnimation::Right)) {
            setSubspriteIndex(static_cast<int>(UnitAnimation::RightMoved));
        }
        else {
            setSubspriteIndex(static_cast<int>(UnitAnimation::Right));
        }
    }
    
    distanceFromLastStep = 0;
}

void Unit::setVelocity(const ui::Point &velocity) {
    this->velocity = ui::Point(velocity.x, 0);
    setSubspriteIndex(static_cast<int>(velocity.x > 0 ? UnitAnimation::Right : UnitAnimation::Left));
}
