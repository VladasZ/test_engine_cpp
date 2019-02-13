//
//  Paths.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "System.hpp"

std::string Paths::assets_directory() {
#ifdef WINDOWS
	return "C:\\Users\\u.zakreuskis\\dev\\projects\\testengine\\Assets\\";
#elif defined (APPLE)
    return std::string() + "/Users/" + System::user_name() + "/dev/projects/testengine/Assets/";
#else
  return std::string() + "/home/" + System::user_name() + "/dev/projects/testengine/Assets/";
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
