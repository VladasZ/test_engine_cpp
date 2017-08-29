
#pragma once

#ifdef _WIN32

#define WINDOWS true

#elif __APPLE__
#include "TargetConditionals.h"
#   define APPLE
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#define IOS true
#elif TARGET_OS_MAC
#define MAC_OS true
#else
#   error "Unknown Apple platform"
#endif
#elif __linux__
// linux
#elif __unix__ // all unices not caught above
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#   error "Unknown compiler"
#endif
