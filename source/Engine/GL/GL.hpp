//
//  GL.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"

class mat4 { };
class vec3 { };

#if IOS
    #import <OpenGLES/ES3/gl.h>
#else
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif

#include "Shader.hpp"

class GL {
public:
	static void setViewport(const Rect& rect) { 
		glViewport((GLint)rect.origin.x, (GLint)rect.origin.y, (GLsizei)rect.size.width, (GLsizei)rect.size.height);
	}
    
    static void unbindImage() {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
};
