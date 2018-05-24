//
//  ClassMemoryInfo.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 25/01/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#if MEMORY_TRACKING

#include "ClassMemoryInfo.hpp"

ClassMemoryInfo::ClassMemoryInfo(const String &name) : className(name) { }

void ClassMemoryInfo::print() const {
    Log("Class: " << className);
    Log("allocated: " << allocated);
    Log("deleted: " << deleted);
    Log("exists: " << allocated - deleted);
}

#endif
