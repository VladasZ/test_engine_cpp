//
//  Shaders.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Shader.hpp"

struct Shaders {

    gl::Shader* ui           ;
    gl::Shader* ui_texture   ;
    gl::Shader* ui_monochrome;

    Shaders();
};
