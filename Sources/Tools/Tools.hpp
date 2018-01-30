#pragma once

#include "Log.hpp"
#include "String.hpp"
#include "StringTools.hpp"
#include "Debug.hpp"
#include "FileManager.hpp"
#include "NonCopyable.hpp"
#include "Platform.h"
#include "System.hpp"
#include "MemoryManaged.hpp"

#define FOR(n) for (int i = 0; i < (n); i++)

#define MAX(container, comp)  (*max_element((container).begin(), (container).end(), (comp)))
#define MIN(container, comp)  (*min_element((container).begin(), (container).end(), (comp)))

#define MMAX(container, type, comp) MIN((container), [] (type v1, type v2) {\
return type comp < type comp;\
})comp;



