//
//  GL.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Platform.h"

#ifdef WINDOWS
    #include <glew.h>
    #include "glfw3.h"

#elif IOS
    #import <OpenGLES/ES3/gl.h>

#elif MAC_OS
    #include <glew.h>
    #include "glfw3.h"
#endif

#include "ShaderManager.hpp"
