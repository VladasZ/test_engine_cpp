//
//  Log.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "STL.hpp"

#define LOCATION __FILE__ , __func__, __LINE__
#define LOCATION_INPUT string file, string function, int line
#define LOCATION_PARAMETERS file, function, line

#define Info(message)    Log::info   ((message), LOCATION)
#define Warning(message) Log::warning((message), LOCATION)
#define Error(message)   Log::error  ((message), LOCATION)
#define Check(value)     Log::check  ((value)  , LOCATION)

#define SAFE(X) \
{\
(X);      \
CheckGLError(__FILE__, __LINE__); \
}

class Log {
    
public:
    
    static void info   (string message, LOCATION_INPUT);
    static void warning(string message, LOCATION_INPUT);
    static void error  (string message, LOCATION_INPUT);
    static void check  (long     value, LOCATION_INPUT);
};

void CheckGLError(const char* file, unsigned line);

