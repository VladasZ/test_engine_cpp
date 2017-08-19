//
//  GL.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#import "Tools.hpp"

#ifdef WINDOWS
    #include <glew.h>
    #include "glfw3.h"
#endif


#ifdef IPHONE
    #import <OpenGLES/ES3/gl.h>
#endif


#ifdef MAC_OS
    #include <glew.h>
    #include "glfw3.h"
#endif


#include "shader.hpp"
