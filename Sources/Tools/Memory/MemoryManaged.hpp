//
//  MemoryManaged.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "MemoryManager.hpp"
#include "ClassMemoryInfo.hpp"

#define  MEMORY_MANAGED(class) : public MemoryManaged<class>
#define _MEMORY_MANAGED(class) , public MemoryManaged<class>

template <class T>
class MemoryManaged {
    
    static string className;
    static int *allocated;
    static int *deleted;
    
public:
    
    static int leaked() {
        return allocated - deleted;
    }
    
    MemoryManaged() {
        if (allocated == nullptr) {
            cout << "31 Initialized class: " << MemoryManaged<T>::className << endl;
            return;
        }
        (*allocated)++;
        MemoryManager::totalObjectsAllocated++;
    }
    
    virtual ~MemoryManaged() {
        if (deleted == nullptr) return;
        (*deleted)++;
        MemoryManager::totalObjectsDeleted++;
    }
};

template <class T>
string MemoryManaged<T>::className = []() {
    auto info = new ClassMemoryInfo(typeid(T).name());
    cout << "48 Initialized class: " << info->className << endl;
    allocated = &info->allocated;
    deleted = &info->deleted;
    MemoryManager::info.push_back(info);
    return info->className;
}();

template <class T>
int * MemoryManaged<T>::allocated;

template <class T>
int * MemoryManaged<T>::deleted;
