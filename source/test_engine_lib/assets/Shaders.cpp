//
//  Shaders.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "Shaders.hpp"

using namespace te;

Shaders::Shaders() {
    ui            = new gl::Shader(Paths::shaders().string(), "ui"           );
    ui_path       = new gl::Shader(Paths::shaders().string(), "ui_path"      );
    ui_texture    = new gl::Shader(Paths::shaders().string(), "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::shaders().string(), "ui_monochrome");

    colored3D       = new gl::Shader(Paths::shaders().string(), "colored3D"      );
    textured3D      = new gl::Shader(Paths::shaders().string(), "textured3D"     );
    diffuse_colored = new gl::Shader(Paths::shaders().string(), "diffuse_colored");
}
