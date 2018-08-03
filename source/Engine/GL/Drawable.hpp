//
//  Drawable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 10/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "MemoryManager.hpp"
#include "NonCopyable.hpp"

class Drawable : public NonCopyable _MEMORY_MANAGED(Drawable) {
    
protected:
    
    virtual void draw() = 0;

public:

    float rotation = 0;
	Color _color;
};
