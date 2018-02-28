//
//  MemoryManaged.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#if MEMORY_TRACKING

#define  MEMORY_MANAGED(class) : public MemoryManaged<class>
#define _MEMORY_MANAGED(class) , public MemoryManaged<class>

#else

#define  MEMORY_MANAGED(class)
#define _MEMORY_MANAGED(class)

#endif

#if MEMORY_TRACKING

#include "MemoryManager.hpp"
#include "ClassMemoryInfo.hpp"

template <class T>
class MemoryManaged {
    
    static string className;
    static int *allocated;
    static int *deleted;
    
    
public:
    
    int _memoryID;
    
    static int leaked() {
        return allocated - deleted;
    }
    
    MemoryManaged() {
        if (!MemoryManager::isTracking) return;
        if (allocated == nullptr) {
            Log("31 Initialized class: " << MemoryManaged<T>::className);
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
string MemoryManaged<T>::className = []() {
    auto info = new ClassMemoryInfo(typeid(T).name());
    Log("48 Initialized class: " << info->className);
    allocated = &info->allocated;
    deleted = &info->deleted;
    MemoryManager::info.push_back(info);
    return info->className;
}();

template <class T>
int * MemoryManaged<T>::allocated;

template <class T>
int * MemoryManaged<T>::deleted;

#endif
