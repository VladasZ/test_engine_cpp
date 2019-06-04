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
#include "CallObj.h"
#endif

std::string Paths::assets_directory() {
#ifdef WINDOWS
    return "C:\\Users\\u.zakreuskis\\.deps\\test_engine\\assets\\";
#elif IOS_BUILD
    return std::string() + objCWorkDirectoryPath() + "/Assets/";
#elif APPLE
    return std::string() + "/Users/" + System::user_name() + "/.deps/test_engine/assets/";
#else
  return std::string() + "/home/" + System::user_name() + "/.deps/test_engine/Assets/";
#endif
}

std::string Paths::shaders_directory() {
    return assets_directory() + "Shaders/";
}

std::string Paths::images_directory() {
    return assets_directory() + "Images/";
}

std::string Paths::models_directory() {
    return assets_directory() + "Models/";
}

std::string Paths::fonts_directory() {
    return assets_directory() + "Fonts/";
}
