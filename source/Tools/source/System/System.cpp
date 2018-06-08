//
//  System.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "System.hpp"
#include "Log.hpp"

#ifdef APPLE
#include <unistd.h>
#include "CallObj.h"
#elif  WINDOWS
#include <Windows.h>
#endif

void System::sleep(float interval) {
    
#ifdef APPLE
    usleep(interval * 1000000);
#elif WINDOWS
	Sleep(DWORD(interval * 1000));
#else 
    NOT_IMPLEMENTED;
#endif
}

int System::random() {
#ifdef APPLE
    return arc4random();
#elif WINDOWS
	NOT_IMPLEMENTED; return 0;
#else
    NOT_IMPLEMENTED; return 0;
#endif
}

int System::random(int range) {
    
#ifdef APPLE
    return arc4random_uniform(range);
#elif WINDOWS
	NOT_IMPLEMENTED; return 0;
#else 
    NOT_IMPLEMENTED; return 0;
#endif
}

