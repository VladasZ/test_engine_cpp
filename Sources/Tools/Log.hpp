//
//  Log.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include "STL.h"

#define Info(message)    Log::info   ((message), __FILE__ , __func__, __LINE__)
#define Warning(message) Log::warning((message), __FILE__ , __func__, __LINE__)
#define Error(message)   Log::error  ((message), __FILE__ , __func__, __LINE__)

class Log {
    
public:
    
    static void info   (string message, string file, string function, int line);
    static void warning(string message, string file, string function, int line);
    static void error  (string message, string file, string function, int line);
};

#endif /* Log_hpp */
