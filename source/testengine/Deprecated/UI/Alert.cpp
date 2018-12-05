//
//  Alert.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/6/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Alert.hpp"

#ifdef WINDOWS
#include <Windows.h>
#elif APPLE
#include "CallObj.h"
#endif

void Alert::show(const std::string& message, const std::string& title) {
#if WINDOWS
    MessageBox(0, message.c_str(), title.c_str(), MB_OK);
#else 
	NOT_IMPLEMENTED;
    //objCShowAlert(message);
#endif
}
