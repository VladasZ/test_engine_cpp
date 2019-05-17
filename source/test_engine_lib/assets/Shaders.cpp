//
//  Shaders.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include   "Paths.hpp"
#include "Shaders.hpp"

Shaders::Shaders() {
    ui            = new gl::Shader(Paths::shaders_directory(), "ui"           );
    ui_path       = new gl::Shader(Paths::shaders_directory(), "ui_path"      );
    ui_texture    = new gl::Shader(Paths::shaders_directory(), "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::shaders_directory(), "ui_monochrome");

    simple3D        = new gl::Shader(Paths::shaders_directory(), "simple3D"       );
    colored3D       = new gl::Shader(Paths::shaders_directory(), "colored3D"      );
    textured3D      = new gl::Shader(Paths::shaders_directory(), "textured3D"     );
    diffuse_colored = new gl::Shader(Paths::shaders_directory(), "diffuse_colored");
}
