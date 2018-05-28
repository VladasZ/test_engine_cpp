//
//  MemoryManaged.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#if MEMORY_TRACKING

#include "Log.hpp"

template <class T>
class MemoryManaged {
    
    static const std::string className;
    static int *allocated;
    static int *deleted;
    
    int _memoryID;

public:
        
    static int leaked() {
        return allocated - deleted;
    }
    
    MemoryManaged() {
        if (!MemoryManager::isTracking) return;
        if (allocated == nullptr) {
            Error(typeid(T).name() << MemoryManaged<T>::className);
            return;
        }
        
#if FULL_MEMORY_OUTPUT
        _memoryID = *allocated;
        Log(MemoryManaged<T>::className << " allocated: " << _memoryID);
#endif
        
        (*allocated)++;
        MemoryManager::totalObjectsAllocated++;
    }
    
    virtual ~MemoryManaged() {
        if (!MemoryManager::isTracking) return;
        if (deleted == nullptr) return;
#if FULL_MEMORY_OUTPUT
        Log(MemoryManaged<T>::className << " deleted:" << _memoryID);
#endif
        (*deleted)++;
        MemoryManager::totalObjectsDeleted++;
    }
};

template <class T>
const std::string MemoryManaged<T>::className = []() {
    MemoryManager::info.push_back(new ClassMemoryInfo(typeid(T).name()));
    ClassMemoryInfo &info = *MemoryManager::info.back();
    Log("48 Initialized class: " << info.className);
    MemoryManaged<T>::allocated = &info.allocated;
    MemoryManaged<T>::deleted = &info.deleted;
    return info.className;
}();

template <class T>
int * MemoryManaged<T>::allocated;

template <class T>
int * MemoryManaged<T>::deleted;

#endif
