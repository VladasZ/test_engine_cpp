//
//  System.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/19/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS
#endif

#ifdef __APPLE__
#if  TARGET_OS_IPHONE
    #define IPHONE
#else
    #define MAC_OS
#endif

#endif

#include "FileManager.hpp"
