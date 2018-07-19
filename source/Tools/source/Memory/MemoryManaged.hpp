//
//  MemoryManaged.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#if MEMORY_TRACKING

//template <class T>
//class ObjectsCounter {
//
//public:
//
//    static inline int created = 0;
//    static inline int deleted = 0;
//
//    static int exists() { return created - deleted; }
//
//
//    ObjectsCounter() {
//        created++;
//    }
//
//    virtual ~ObjectsCounter() {
//        deleted++;
//    }
//};

#include "Log.hpp"

template <class T>
class MemoryManaged {

public:

    static inline int created = 0;
    static inline int deleted = 0;

    static int exists() { return created - deleted; }

    MemoryManaged() {
        created++;
    }

    virtual ~MemoryManaged() {
        deleted++;
    }
};

#endif
