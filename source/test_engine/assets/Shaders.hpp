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

    gl::Shader* ui;
    gl::Shader* ui_path;
    gl::Shader* ui_texture;
    gl::Shader* ui_monochrome;

    gl::Shader* simple3D;
    gl::Shader* colored3D;
    gl::Shader* textured3D;
    gl::Shader* diffuse_colored;
    gl::Shader* fog;

	gl::Shader* sprite;
    gl::Shader* textured_sprite;

    Shaders();

    void set_screen_resolution(const gm::Size&);

};
