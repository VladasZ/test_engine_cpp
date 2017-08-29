//
//  Buffer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Types.h"

class Buffer {
    
public:
    
    int id;
    
    Buffer(const int &size, const void *data, UInt type);
    
    void setVertexPointer(const int &location) const;
    void setColorPointer(const int &location) const;
};
