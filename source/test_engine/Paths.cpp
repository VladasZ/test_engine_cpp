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
#include "Platform.hpp"
#include "SystemInfo.hpp"

#ifdef IOS_BUILD
#include "CallObj.hpp"
#endif

using namespace cu;
using namespace te;


Path Paths::root = [] {
#ifdef IOS_BUILD
    return Path() / obj_c::work_directory_path();
#elif ANDROID_BUILD
    return "";
#elif DESKTOP_BUILD
    return System::home() / ".deps/test_engine";
#endif
}();

Path Paths::assets = SystemInfo::is_android ?  "" : (root / "Assets");

Path Paths::images = assets / "Images";
Path Paths::models = assets / "Models";
Path Paths::fonts  = assets / "Fonts";
Path Paths::downloads = System::home() / "Downloads";

Path Paths::Shaders::root = assets / "Shaders";

Path Paths::Shaders::ui        = root / "ui";
Path Paths::Shaders::sprites   = root / "sprites";
Path Paths::Shaders::isometric = root / "isometric";
Path Paths::Shaders::include   = root / "include";
Path Paths::Shaders::test      = root / "test";

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
