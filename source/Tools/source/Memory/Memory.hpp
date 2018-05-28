//
//  MemoryManager.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#define MEMORY_TRACKING false

#if MEMORY_TRACKING

#define MEMORY_TEST false
#define MEMORY_BENCHMARK false
#define FULL_MEMORY_OUTPUT false

#define  MEMORY_MANAGED(type) : public MemoryManaged<type>
#define _MEMORY_MANAGED(type) , public MemoryManaged<type>

#define MEMORY_MANAGER_INVISIBLE(code)\
MemoryManager::isTracking = false; do { code } while(false); MemoryManager::isTracking = true;

#include "ClassMemoryInfo.hpp"
#include "MemoryManager.hpp"
#include "MemoryManaged.hpp"

#else

#define MEMORY_MANAGER_INVISIBLE(code) do { code } while (false);

#define  MEMORY_MANAGED(type)
#define _MEMORY_MANAGED(type)

#endif
