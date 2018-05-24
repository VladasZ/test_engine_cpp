//
//  System.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Platform.h"
#include "System.hpp"
#include "Debug.hpp"
#include "Log.hpp"

#ifdef APPLE
#include <unistd.h>
#include "CallObj.h"
#endif

#ifdef WINDOWS
#include <Windows.h>
#endif

void System::sleep(float interval) {
    
#ifdef APPLE
    usleep(interval * 1000000);
#endif
    
#ifdef WINDOWS
	Sleep(interval * 1000);
#endif
}

int System::random() {
    
#ifdef APPLE
    return arc4random();
#endif
    
#ifdef WINDOWS
	NOT_IMPLEMENTED;
    return 0;
#endif
}

int System::random(int range) {
    
#ifdef APPLE
    return arc4random_uniform(range);
#endif
    
#ifdef WINDOWS
	NOT_IMPLEMENTED;
    return 0;
#endif
}

