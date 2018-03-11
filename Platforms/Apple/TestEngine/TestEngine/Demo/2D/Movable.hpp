//
//  Movable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Sprite.hpp"

class Movable : public Sprite {
    
public:

    using Sprite::Sprite;
    
    Point velocity;
    
    void update();
    
};
