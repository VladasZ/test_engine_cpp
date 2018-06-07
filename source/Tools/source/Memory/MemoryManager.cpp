//
//  MemoryManager.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "MemoryManager.hpp"
#include "ClassMemoryInfo.hpp"

#if MEMORY_TRACKING

Array<ClassMemoryInfo *> MemoryManager::info;

bool MemoryManager::isTracking = true;

int MemoryManager::totalObjectsAllocated = 0;
int MemoryManager::totalObjectsDeleted = 0;

int MemoryManager::totalObjectsExist() {
    return totalObjectsAllocated - totalObjectsDeleted;
}

void MemoryManager::printDump() {
    
    for (auto info : MemoryManager::info) {
        info->print();
        Endl;
    }
    
    Log("Objects created: " << MemoryManager::totalObjectsAllocated);
    Log("Objects deleted: " << MemoryManager::totalObjectsDeleted);
    Log("Objects exist: " << MemoryManager::totalObjectsExist());
}

#endif
