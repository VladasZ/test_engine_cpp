//
//  Debug.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "MemoryTest.hpp"

#define MEMORY_TEST false
#define DEBUG_OUTPUT false

#ifdef DEBUG

#define NOT_IMPLEMENTED Debug::notImplemented(LOCATION)

#else

#define NOT_IMPLEMENTED

#endif

class Debug {
    
    Debug();
    
public:
    
    static void notImplemented(LOCATION_INPUT);
};
