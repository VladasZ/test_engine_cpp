//
//  BufferConfiguration.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Types.h"

class Buffer;

class BufferConfiguration {
    
    UInt *configuration = nullptr;
    UInt size = 1;
    
    UInt vertexSize = 0;
    
    UInt strideForIndex(int index) const;
    
    void setPointers() const;

    friend Buffer;
    
public:
    
    BufferConfiguration(UInt firstParam, UInt secondParam = 0, UInt thirdParam = 0);
    ~BufferConfiguration();
    
    
};

