//
//  Paths.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "System.hpp"

#ifdef IOS_BUILD
#include "CallObj.hpp"
#endif

using namespace te;
using namespace Paths;

Path Paths::root() {
#ifdef IOS_BUILD
    return Path() / obj_c::work_directory_path;
#elif WINDOWS
    Path users = "C:/Users";
#elif APPLE
    Path users = "/Users";
#else
    Path users = "/home";
#endif
#ifndef IOS_BUILD
    return users / System::user_name() / ".deps/test_engine";
#endif
}

Path Paths::assets() {
    return root() / "Assets";
}

Path Paths::shaders() {
    return assets() / "Shaders";
}

Path Paths::images() {
    return assets() / "Images";
}

Path Paths::models() {
    return assets() / "Models";
}

Path Paths::fonts() {
    return assets() / "Fonts";
}

PathsArray Paths::ls(Path path) {
#ifdef IOS_BUILD
    const auto files = obj_c::ls(path.string());
    return { files.begin(), files.end() };
#else
    return { "NOT IMPLEMENTED ON THIS PLATFORM" };
#endif
}
