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

#ifdef IOS_BUILD
#include "CallObj.hpp"
#endif

using namespace cu;
using namespace te;
using namespace Paths;

Path Paths::root() {
#ifdef IOS_BUILD
    return Path() / obj_c::work_directory_path;
#elif ANDROID_BUILD
    return "";
#endif
#ifdef DESKTOP_BUILD
    return System::home() / ".deps/test_engine";
#endif
}

Path Paths::assets() {
#ifdef ANDROID_BUILD
    return "";
#else
    return root() / "Assets";
#endif
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

Path Paths::downloads() {
    return System::home() / "Downloads";
}

Path Paths::Shaders::root() {
	return assets() / "Shaders";
}
Path Paths::Shaders::ui() {
	return root() / "ui";
}

Path Paths::Shaders::sprites() {
	return root() / "sprites";
}

Path Paths::Shaders::isometric() {
	return root() / "isometric";
}

Path Paths::Shaders::include() {
    return root() / "include";
}

Path Paths::Shaders::test() {
    return root() / "test";
}

void Paths::dump() {

    static const std::vector<Path> all = {
            root(),
            assets(),
            images(),
            models(),
            fonts(),
            Shaders::root(),
            Shaders::ui(),
            Shaders::sprites(),
            Shaders::isometric(),
            Shaders::include(),
            Shaders::test()
    };

    for(auto path : all) {
        Log(path);
    }

}
