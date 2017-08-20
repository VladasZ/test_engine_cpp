//
//  Log.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <iostream>
using namespace std;

#define LOCATION __FILE__ , __func__, __LINE__
#define LOCATION_INPUT string file, string function, int line
#define LOCATION_PARAMETERS file, function, line

#define Info(message)    Log::info   ((message), LOCATION)
#define Warning(message) Log::warning((message), LOCATION)
#define Error(message)   Log::error  ((message), LOCATION)

class Log {
    
public:
    
    static void info   (string message, LOCATION_INPUT);
    static void warning(string message, LOCATION_INPUT);
    static void error  (string message, LOCATION_INPUT);
};

