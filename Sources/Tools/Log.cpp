//
//  Log.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Tools.hpp"
#include "GL.hpp"

#ifdef WINDOWS
#define INFO_ICON "HEARTH"
#else
#define INFO_ICON "💚"
#endif

enum LogType {
    
    LogTypeInfo,
    LogTypeWarning,
    LogTypeError
};

string logTypeString(LogType type) {
    
    switch (type) {
        case LogTypeInfo:    return INFO_ICON + string(" INFO ") + INFO_ICON;
        case LogTypeWarning: return "💛 WARNING 💛";
        case LogTypeError:   return "❤️ ERROR ❤️";
    }
}

void log(string message, LOCATION_INPUT, LogType type) {
    
    auto fileName = StringTools::fileName(file);
    
    cout << "[" << logTypeString(type) << "] [" << fileName << "::" << function << " - " << line << "] " << message << endl;
}

void Log::info(string message, LOCATION_INPUT) {
        
    log(message, LOCATION_PARAMETERS, LogTypeInfo);
}

void Log::warning(string message, LOCATION_INPUT) {
    
    log(message, LOCATION_PARAMETERS, LogTypeWarning);
}

void Log::error(string message, LOCATION_INPUT) {
    
    log(message, LOCATION_PARAMETERS, LogTypeError);
}

void Log::check (long value, LOCATION_INPUT) {
    if (value != 0) {
        log("", LOCATION_PARAMETERS, LogTypeError);
    }
}

void CheckGLError(const char* file, unsigned line) {
    GLenum err = glGetError();
    while(err != GL_NO_ERROR) {
        char* error = new char[255];
        switch(err) {
            case GL_INVALID_OPERATION:
                strcpy(error, "INVALID_OPERATION");
                break;
            case GL_INVALID_ENUM:
                strcpy(error, "INVALID_ENUM");
                break;
            case GL_INVALID_VALUE:
                strcpy(error, "INVALID_VALUE");
                break;
            case GL_OUT_OF_MEMORY:
                strcpy(error, "OUT_OF_MEMORY");
                break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
                strcpy(error, "INVALID_FRAMEBUFFER_OPERATION");
                break;
            default:
                strcpy(error, "Unknown error");
                break;
        }
        //CROSS_ASSERT(false, "Rendering error number: %s in %s : %d", error, file, line);
        delete[] error;
        err = glGetError();
    }
}
