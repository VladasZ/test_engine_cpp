//
//  Debug.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#ifdef DEBUG

#include "Debug.hpp"
#include "GL.hpp"

void CheckGLError(LOCATION_PARAMETERS) {
    GLenum err = glGetError();
    while(err != GL_NO_ERROR) {
        char* error = new char[255];
        switch(err) {
            case GL_INVALID_OPERATION:
            strcpy(error, "GL_INVALID_OPERATION");
            break;
            case GL_INVALID_ENUM:
            strcpy(error, "GL_INVALID_ENUM");
            break;
            case GL_INVALID_VALUE:
            strcpy(error, "GL_INVALID_VALUE");
            break;
            case GL_OUT_OF_MEMORY:
            strcpy(error, "GL_OUT_OF_MEMORY");
            break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:
            strcpy(error, "GL_INVALID_FRAMEBUFFER_OPERATION");
            break;
            default:
            strcpy(error, "Unknown error");
            break;
        }
        
        
        __logE("Rendering error: " << error, fileName, function, line);
        delete[] error;
        err = glGetError();
    }
}

#endif

