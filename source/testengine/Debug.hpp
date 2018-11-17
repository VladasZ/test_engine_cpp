//
//  Debug.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Log.hpp"

class Label;

#ifdef DEBUG

#define DEBUG_VIEW true
#define RENDERING_ERRORS_OUTPUT true
#define SHADER_COMPILER_OUTPUT true
#define IMAGES_LOADING_OUTPUT true
#define DRAW_DEBUG_FRAMES true

#if RENDERING_ERRORS_OUTPUT
#define GL(x) (x); CheckGLError(LOCATION_INFO)
#else
#define GL(x) x
#endif

#define CHECK_FRAMEBUFFER CheckFramebufferStatus(GL_FRAMEBUFFER, LOCATION_INFO)

void CheckGLError(LOCATION_PARAMETERS);
void CheckFramebufferStatus(int target, LOCATION_PARAMETERS);

#else

#define GL(x) x

#endif

struct Debug {
    static inline Label* infoLabel;
};
