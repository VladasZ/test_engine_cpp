//
//  CallObj.c
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/19/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "CallObj.h"
#include "OBJBridge.h"


const char * workDirectoryPath() {
    return [OBJBridge workDirectoryPath];
}

