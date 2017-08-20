//
//  System.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Platform.h"
#include "System.hpp"
#include "Log.hpp"

#ifdef APPLE
#include <unistd.h>
#endif

void System::sleep(double interval) {
    
#ifdef APPLE
    usleep(interval * 1000000);
#endif
    
#ifdef WINDOWS
    NOT_IMPLEMENTED
#endif
}

UInt System::random() {
    
#ifdef APPLE
    return arc4random();
#endif
    
#ifdef WINDOWS
    NOT_IMPLEMENTED
    return 0;
#endif
}

UInt System::random(Int range) {
    
#ifdef APPLE
    return arc4random_uniform(range);
#endif
    
#ifdef WINDOWS
    NOT_IMPLEMENTED
    return 0;
#endif
}
