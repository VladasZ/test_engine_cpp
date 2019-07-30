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
    ui            = new gl::Shader(Paths::Shaders::ui().string(), "ui"           );
    ui_path       = new gl::Shader(Paths::Shaders::ui().string(), "ui_path"      );
    ui_texture    = new gl::Shader(Paths::Shaders::ui().string(), "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::Shaders::ui().string(), "ui_monochrome");

    colored3D       = new gl::Shader(Paths::Shaders::isometric().string(), "colored3D"      );
    textured3D      = new gl::Shader(Paths::Shaders::isometric().string(), "textured3D"     );
    diffuse_colored = new gl::Shader(Paths::Shaders::isometric().string(), "diffuse_colored");

	sprite = new gl::Shader(Paths::Shaders::sprites().string(), "sprite");
}
