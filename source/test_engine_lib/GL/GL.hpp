//
//  GL.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "Color.hpp"

#include "Matrix4.hpp"

#if IOS_BUILD
    #import <ES3/gl.h>
#else
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif

#include "Shader.hpp"

namespace GL {
    void set_viewport(const Rect& rect);
    void set_clear_color(const Color& color);
};
