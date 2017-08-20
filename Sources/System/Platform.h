
#pragma once

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define WINDOWS
#endif

#ifdef __APPLE__
#define APPLE
#if  TARGET_OS_IPHONE
#define IPHONE
#else
#define MAC_OS
#endif

#endif
