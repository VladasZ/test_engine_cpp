////
////  Log.hpp
////  TestEngine
////
////  Created by Vladas Zakrevskis on 7/28/17.
////  Copyright © 2017 VladasZ. All rights reserved.
////
//
#pragma once

//
//#define LOCATION __FILE__ , __func__, __LINE__
//#define LOCATION_INPUT const char* file, const char* function, int line
//#define LOCATION_PARAMETERS file, function, line
//
#define Info(message)   message //Log::info   ((message), LOCATION)
#define Warning(message) message//Log::warning((message), LOCATION)
#define Error(message)   message//Log::error  ((message), LOCATION)
//

#define SAFE(X) \
{\
(X);      \
CheckGLError(__FILE__, __LINE__); \
}


//void CheckGLError(const char* file, unsigned line);
//
