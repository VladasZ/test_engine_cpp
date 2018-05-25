//
//  World.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

class Movable;
class Sprite;

class World {
    
    std::vector<Movable *> movableObjects;
    std::vector<Sprite *> objects;

public:
    
    World();
    
    void addSprite(Sprite *sprite);
    
    void update();
    
    void setup();
};

extern World world;
