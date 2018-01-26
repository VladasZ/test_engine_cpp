//
//  MemoryManager.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#if MEMORY_TRACKING


#include "MemoryManager.hpp"
#include "ClassMemoryInfo.hpp"

vector<ClassMemoryInfo *> MemoryManager::info;

bool MemoryManager::isTracking = true;

int MemoryManager::totalObjectsAllocated = 0;
int MemoryManager::totalObjectsDeleted = 0;

int MemoryManager::totalObjectsExist() {
    return totalObjectsAllocated - totalObjectsDeleted;
}

void MemoryManager::printDump() {
    
    for (auto info : MemoryManager::info) {
        info->print();
        cout << endl;
    }
    
    cout << "Objects created: " << MemoryManager::totalObjectsAllocated << endl;
    cout << "Objects deleted: " << MemoryManager::totalObjectsDeleted << endl;
    cout << "Objects exist: " << MemoryManager::totalObjectsExist() << endl;
}

#endif
