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
    ui_texture    = new gl::Shader(Paths::shaders_directory(), "ui_texture"   );
    ui_monochrome = new gl::Shader(Paths::shaders_directory(), "ui_monochrome");
}
