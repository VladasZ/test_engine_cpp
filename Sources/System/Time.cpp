//
//  Time.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/3/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Time.hpp"
#include <chrono>

using namespace std::chrono;

long long Time::now() {
    
    long long ms = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    
    return ms;
}

UInt Time::interval() {
    
    static long long prevInterval = 1;
    
    UInt result = UInt(now() - prevInterval);
    prevInterval = now();
    
    if (result == 0) return 1;
    
    return result;
}
