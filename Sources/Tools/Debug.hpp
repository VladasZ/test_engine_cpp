//
//  Debug.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "MemoryTest.hpp"

#ifdef DEBUG

#define MEMORY_TRACKING true
#define MEMORY_TEST false
#define MEMORY_BENCHMARK false
#define FULL_MEMORY_OUTPUT false
#define DEBUG_VIEW true

#define NOT_IMPLEMENTED Error("Not implemented")

#define GL(x) (x); CheckGLError(LOCATION_INFO)

void CheckGLError(LOCATION_PARAMETERS);

#else

#define GL(x) x

#endif
