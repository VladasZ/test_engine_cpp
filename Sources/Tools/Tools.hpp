#pragma once

#define TEST_STRING true

#if TEST_STRING
#define String TestString
#else
#define String string
#endif

#include "TestString.hpp"
#include "Log.hpp"
#include "Debug.hpp"
#include "MemoryManaged.hpp"
#include "FileManager.hpp"
#include "NonCopyable.hpp"
#include "Platform.h"
#include "System.hpp"
#include "Alert.hpp"

#define FOR(n) for (int i = 0; i < (n); i++)

#define MAX(container, comp)  (*max_element((container).begin(), (container).end(), (comp)))
#define MIN(container, comp)  (*min_element((container).begin(), (container).end(), (comp)))

#define MMAX(container, type, comp) MIN((container), [] (type v1, type v2) {\
return type comp < type comp;\
})comp;


