//
//  Alert.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/6/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Alert.hpp"

#ifdef WINDOWS
#include <Windows.h>
#else
#include "CallObj.h"
#endif

void Alert::show(const String&message, const String& title) {
#if WINDOWS
    MessageBox(0, message.c_str(), title.c_str(), MB_OK);
#else 
    objCShowAlert(message);
#endif
}
