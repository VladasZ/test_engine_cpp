//
//  Drawable.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 10/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "Point.hpp"
#include "BufferConfiguration.hpp"
#include "MemoryManaged.hpp"
#include "NonCopyable.hpp"

class Buffer;
class BufferData;

class Drawable : public NonCopyable _MEMORY_MANAGED(Drawable) {
    
protected:
    
    virtual void draw() = 0;

public:

    float rotation = 0;
	Color _color;
};
