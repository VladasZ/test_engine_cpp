//
//  Paths.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include <vector>

#include "Log.hpp"
#include "Paths.hpp"
#include "System.hpp"
#include "Target.hpp"
#include "SystemInfo.hpp"

#ifdef IOS_BUILD
#include "CallObj.hpp"
#endif

using namespace cu;
using namespace te;


const Path Paths::root = [] {
#ifdef IOS_BUILD
    return Path() / obj_c::work_directory_path();
#elif ANDROID_BUILD
    return "";
#elif DESKTOP_BUILD
    return System::home() / ".deps/test_engine";
#endif
}();

const Path Paths::assets = SystemInfo::is_android ?  "" : (root / "Assets");

const Path Paths::images = assets / "Images";
const Path Paths::models = assets / "Models";
const Path Paths::fonts  = assets / "Fonts";
const Path Paths::downloads = System::home() / "Downloads";

const Path Paths::Shaders::root = assets / "Shaders";

const Path Paths::Shaders::ui        = root / "ui";
const Path Paths::Shaders::sprites   = root / "sprites";
const Path Paths::Shaders::isometric = root / "isometric";
const Path Paths::Shaders::include   = root / "include";
const Path Paths::Shaders::test      = root / "test";

void Paths::dump() {

    Logvar(System::user_name);
    Logvar(System::home);
    Logvar(System::home() / ".deps/test_engine");

    Logvar(root);
    Logvar(assets);
    Logvar(images);
    Logvar(models);
    Logvar(fonts);
    Logvar(Shaders::root);
    Logvar(Shaders::ui);
    Logvar(Shaders::sprites);
    Logvar(Shaders::isometric);
    Logvar(Shaders::include);
    Logvar(Shaders::test);

}
