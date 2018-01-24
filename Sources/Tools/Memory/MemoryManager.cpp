//
//  MemoryManager.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "MemoryManager.hpp"
#include "ClassMemoryInfo.hpp"

vector<ClassMemoryInfo *> MemoryManager::info;

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
}
