//
//  Shaders.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "Shaders.hpp"
#include "GLWrapper.hpp"
#include "ShaderCompiler.hpp"

using namespace te;

Shaders::Shaders() {

    ShaderCompiler::includes_path = Paths::Shaders::include;

    simple = new gl::Shader(Paths::Shaders::test / "simple");
    
    if (GL::is_gl2) {
        
        ui            = new gl::Shader(Paths::Shaders::test / "simple");
        ui_path       = new gl::Shader(Paths::Shaders::test / "simple");
        ui_texture    = new gl::Shader(Paths::Shaders::test / "simple");
        ui_monochrome = new gl::Shader(Paths::Shaders::test / "simple");

        colored3D       = new gl::Shader(Paths::Shaders::test / "simple");
        textured3D      = new gl::Shader(Paths::Shaders::test / "simple");
        diffuse_colored = new gl::Shader(Paths::Shaders::test / "simple");
        fog             = new gl::Shader(Paths::Shaders::test / "simple");

        sprite = new gl::Shader(Paths::Shaders::test / "simple");
        
        return;
    }

    ui            = new gl::Shader(Paths::Shaders::ui / "ui"           );
    ui_path       = new gl::Shader(Paths::Shaders::ui / "ui_path"      );
    ui_texture    = new gl::Shader(Paths::Shaders::ui / "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::Shaders::ui / "ui_monochrome");

    simple3D        = new gl::Shader(Paths::Shaders::isometric / "simple3D"       );
    colored3D       = new gl::Shader(Paths::Shaders::isometric / "colored3D"      );
    textured3D      = new gl::Shader(Paths::Shaders::isometric / "textured3D"     );
    diffuse_colored = new gl::Shader(Paths::Shaders::isometric / "diffuse_colored");
    fog             = new gl::Shader(Paths::Shaders::isometric / "fog"            );

    sprite = new gl::Shader(Paths::Shaders::sprites / "sprite");
        
}
