//
//  CallObj.c
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/19/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "CallObj.h"
#include "OBJBridge.h"

void obj_c_show_alert(const char *message) {
    [OBJBridge showAlert:message];
}

const char * obj_c_work_directory_path() {
    return [OBJBridge workDirectoryPath];
}

