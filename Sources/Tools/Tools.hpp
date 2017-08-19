#pragma once

//#define WINDOWS defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)


#include "System.hpp"
#include "STL.hpp"
#include "Log.hpp"
#include "StringTools.hpp"

#ifdef WINDOWS
#include <windows.h>
#endif