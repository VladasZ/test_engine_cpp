//
//  Debug.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#ifdef DEBUG

#include <string.h>

#include "Debug.hpp"
#include "GL.hpp"

void check_gl_error(LOCATION_PARAMETERS) {
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
            check_framebuffer_status(GL_FRAMEBUFFER, fileName, function, line);
            break;
            default:
            strcpy(error, "Unknown error");
            break;
        }

        UTILS_INTERNAL_LOG_ERROR("Rendering error: " << error, fileName, function, line);
        delete[] error;
        err = glGetError();
    }
}

void check_framebuffer_status(unsigned int target, LOCATION_PARAMETERS) {
    auto error = glCheckFramebufferStatus(target);

    if (!error || error == GL_FRAMEBUFFER_COMPLETE) return;

    std::string errorString;

    switch (error) {
        case GL_FRAMEBUFFER_UNDEFINED:
            errorString = "GL_FRAMEBUFFER_UNDEFINED";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
            errorString = "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
            errorString = "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
            break;
        case GL_INVALID_ENUM:
            errorString = "GL_INVALID_ENUM";
            break;
        default:
            errorString = "UNKNOWN";
            break;
    }

    UTILS_INTERNAL_LOG_ERROR("Framebuffer error: " << errorString, fileName, function, line);
}

#endif
