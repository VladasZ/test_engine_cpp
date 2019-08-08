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
    ui            = new gl::Shader(Paths::Shaders::ui(), "ui"           );
    ui_path       = new gl::Shader(Paths::Shaders::ui(), "ui_path"      );
    ui_texture    = new gl::Shader(Paths::Shaders::ui(), "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::Shaders::ui(), "ui_monochrome");

    colored3D       = new gl::Shader(Paths::Shaders::isometric(), "colored3D"      );
    textured3D      = new gl::Shader(Paths::Shaders::isometric(), "textured3D"     );
    diffuse_colored = new gl::Shader(Paths::Shaders::isometric(), "diffuse_colored");

	sprite = new gl::Shader(Paths::Shaders::sprites(), "sprite");
}
