//
//  Shaders.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "Shaders.hpp"
#include "ShaderCompiler.hpp"

using namespace te;

Shaders::Shaders() {

	ShaderCompiler::includes_path = Paths::Shaders::include();

	simple = new gl::Shader(Paths::Shaders::test() / "simple");

    ui            = new gl::Shader(Paths::Shaders::ui() / "ui"           );
    ui_path       = new gl::Shader(Paths::Shaders::ui() / "ui_path"      );
    ui_texture    = new gl::Shader(Paths::Shaders::ui() / "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::Shaders::ui() / "ui_monochrome");

    colored3D       = new gl::Shader(Paths::Shaders::isometric() / "colored3D"      );
    textured3D      = new gl::Shader(Paths::Shaders::isometric() / "textured3D"     );
    diffuse_colored = new gl::Shader(Paths::Shaders::isometric() / "diffuse_colored");
    fog             = new gl::Shader(Paths::Shaders::isometric() / "fog"            );

	sprite = new gl::Shader(Paths::Shaders::sprites() / "sprite");
}
