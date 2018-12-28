//
//  Paths.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Paths.hpp"

std::string Paths::assets_directory() {
#ifdef WINDOWS
	return "C:\\Users\\u.zakreuskis\\dev\\projects\\testengine\\Assets\\";
#elif defined (APPLE)
    return "/Users/vladaszakrevskis/dev/projects/testengine/Assets/";
#else
  return "/home/vladas/dev/projects/testengine/Assets/";
#endif
}

std::string Paths::images_directory() {
    return assets_directory() + "Images/";
}

std::string Paths::fonts_directory() {
    return assets_directory() + "Fonts/";
}
