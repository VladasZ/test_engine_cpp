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
    MessageBox(0, message, title, MB_OK);
#else 
    objCShowAlert(message);
#endif
}
