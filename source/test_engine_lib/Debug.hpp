//
//  Debug.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Log.hpp"


#ifdef DEBUG

#define DEBUG_VIEW
#define RENDERING_ERRORS_OUTPUT true
#define SHADER_COMPILER_OUTPUT true
#define IMAGES_LOADING_OUTPUT false
#define DRAW_DEBUG_FRAMES false

#if RENDERING_ERRORS_OUTPUT
#define GL(x) (x); check_gl_error(LOCATION_INFO)
#else
#define GL(x) x
#endif

#define CHECK_FRAMEBUFFER check_framebuffer_status(GL_FRAMEBUFFER, LOCATION_INFO)

void check_gl_error(LOCATION_PARAMETERS);
void check_framebuffer_status(unsigned int target, LOCATION_PARAMETERS);

#else

#define GL(x) x

#endif

