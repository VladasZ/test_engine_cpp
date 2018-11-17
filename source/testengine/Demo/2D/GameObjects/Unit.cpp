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
        if (getSubspriteIndex() == (int)UnitAnimation::Left) {
            setSubspriteIndex((int)UnitAnimation::LeftMoved);
        }
        else {
            setSubspriteIndex((int)UnitAnimation::Left);
        }
    }
    else {
        if (getSubspriteIndex() == (int)UnitAnimation::Right) {
            setSubspriteIndex((int)UnitAnimation::RightMoved);
        }
        else {
            setSubspriteIndex((int)UnitAnimation::Right);
        }
    }
    
    distanceFromLastStep = 0;
}

void Unit::setVelocity(const Point &velocity) {
    this->velocity = Point(velocity.x, 0);    
    setSubspriteIndex((int)(velocity.x > 0 ? UnitAnimation::Right : UnitAnimation::Left));
}
