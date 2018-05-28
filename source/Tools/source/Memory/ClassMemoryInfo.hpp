//
//  ClassMemoryInfo.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 25/01/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Memory.hpp"

#if MEMORY_TRACKING

#include <string>

class ClassMemoryInfo {
    
public:
    
    int allocated = 0;
    int deleted = 0;
    
    const std::string className;
    
    ClassMemoryInfo(const std::string &name);
    
    void print() const;
};

#endif
