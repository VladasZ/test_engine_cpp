//
//  GL.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Platform.h"

#include <glm.hpp>
using namespace glm;

#ifdef WINDOWS
    #include <glew.h>
    #include "glfw3.h"

#elif IOS
    #import <OpenGLES/ES3/gl.h>

#elif MAC_OS
    #include <glew.h>
    #include "glfw3.h"
#endif

#include "Shader.hpp"
#include "Draw.hpp"
