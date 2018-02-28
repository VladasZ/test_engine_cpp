//
//  Log.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#ifdef DEBUG

#define LOG_LOCATION_ENABLED false

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#if LOG_LOCATION_ENABLED
#define LOCATION << "[" << __FILENAME__ << "::" << __func__ << " - " << __LINE__ << "] "
#else
#define LOCATION << " "
#endif

#define __log(message, type)\
cout << "[" << type << "]" \
LOCATION\
<< message << endl;

#define Log(message) __log(message, "💚 INFO 💚")
#define Warning(message) __log(message, "💛 WARNING 💛")
#define Error(message) __log(message, "❤️ ERROR ❤️")
#define Endl cout << endl

#else

#define Log(message)
#define Warning(message)
#define Error(message)
#define Endl

#endif
