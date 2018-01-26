//
//  ClassMemoryInfo.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 25/01/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#if MEMORY_TRACKING

#include "ClassMemoryInfo.hpp"

ClassMemoryInfo::ClassMemoryInfo(const string &name) : className(name) { }

void ClassMemoryInfo::print() const {
    cout << "Class: " << className << endl;
    cout << "allocated: " << allocated << endl;
    cout << "deleted: " << deleted << endl;
    cout << "exists: " << allocated - deleted << endl;
}

#endif
