//
//  MemoryManager.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#if MEMORY_TRACKING

#include <vector>

#include "ClassMemoryInfo.hpp"

#define MEMORY_MANAGER_INVISIBLE(code)\
MemoryManager::isTracking = false;\
do {\
code\
} while(false);\
MemoryManager::isTracking = true;

class ClassMemoryInfo;

class MemoryManager {
    
    MemoryManager();
    
public:
    
    static bool isTracking;
    
    static std::vector<ClassMemoryInfo *> info;
    
    static int totalObjectsAllocated;
    static int totalObjectsDeleted;
    
    static int totalObjectsExist();
    
    static void printDump();
    
};

#else

#define MEMORY_MANAGER_INVISIBLE(code) do { code } while (false);

#endif
