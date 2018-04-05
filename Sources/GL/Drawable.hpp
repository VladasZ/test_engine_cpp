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

class Buffer;
class BufferData;

class Drawable : public NonCopyable _MEMORY_MANAGED(Drawable) {
    
protected:
    
    Buffer *buffer = nullptr;
    
    virtual void setupBuffer();
    
    virtual void draw() = 0;
    virtual BufferData *getBufferData() = 0;
    virtual const BufferConfiguration bufferConfiguration() const;
    
public:
    
    float rotation;
    
    Color color;
};
