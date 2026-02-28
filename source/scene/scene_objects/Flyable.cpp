//
//  Flyable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Flyable.hpp"

using namespace gm;
using namespace scene;


void Flyable::fly(Direction direction) {

    Vector3 vel { this->direction().point() };
    Vector3 side { vel.cross({ 0, 0, 1 }) };
    vel.normalize();
    vel *= flying_speed;

    side.normalize();
    side *= flying_speed;

    if (direction == Direction::Forward) {
        velocity = { vel.x, vel.y };
    }

    if (direction == Direction::Back) {
        velocity = { -vel.x, -vel.y };
    }

    if (direction == Direction::Left) {
        velocity = { -side.x, -side.y };
    }

    if (direction == Direction::Right) {
        velocity = { side.x, side.y };
    }

    if (direction == Direction::Up) {
        velocity = { 0, 0, flying_speed };
    }

    if (direction == Direction::Down) {
        velocity = { 0, 0, -flying_speed };
    }
}
