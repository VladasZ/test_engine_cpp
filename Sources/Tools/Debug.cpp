//
//  Debug.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Debug.hpp"
#include "GL.hpp"

//void Debug::notImplemented(LOCATION_INPUT) {
//    
//   // Log::error("Not implemented", LOCATION_PARAMETERS);
//}
//

void CheckGLError(const char* file, int line) {
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
        
        
        cout << "Rendering error number: " << error << " in " << file << " : " << line << endl;
        delete[] error;
        err = glGetError();
    }
}

