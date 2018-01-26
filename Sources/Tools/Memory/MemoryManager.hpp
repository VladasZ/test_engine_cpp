//
//  MemoryManager.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/24/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#if MEMORY_TRACKING

class ClassMemoryInfo;

class MemoryManager {
    
    MemoryManager();
    
public:
    
    static bool isTracking;
    
    static vector<ClassMemoryInfo *> info;
    
    static int totalObjectsAllocated;
    static int totalObjectsDeleted;
    
    static int totalObjectsExist();
    
    static void printDump();
    
};

#endif
