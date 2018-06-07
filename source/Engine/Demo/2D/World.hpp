//
//  World.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Array.hpp"

class Movable;
class Sprite;

class World {
    
    Array<Movable *> movableObjects;
    Array<Sprite *> objects;

public:
    
    World();
    
    void addSprite(Sprite *sprite);
    
    void update();
    
    void setup();
};

extern World world;
