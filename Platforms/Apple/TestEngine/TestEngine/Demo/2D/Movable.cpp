//
//  Movable.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Movable.hpp"


void Movable::update() {
    setPosition(_position + velocity);
}
