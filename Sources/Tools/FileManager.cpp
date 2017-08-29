
#include "Platform.h"
#include "FileManager.hpp"
#include "Log.hpp"
#include "Debug.hpp"

#ifdef APPLE
#include "CallObj.h"
#elif WINDOWS
#include <Windows.h>
#endif

const string FileManager::assetsDirectory() {
    
#ifdef APPLE
    return workDirectoryPath() + string("/Assets/");
#endif
    
#ifdef WINDOWS
    return "../../../../Assets/";
#endif
    
    NOT_IMPLEMENTED;
    return "";
}

const string FileManager::workDirectory() {
    
#ifdef WINDOWS
	char result[MAX_PATH];
	return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
#endif

    NOT_IMPLEMENTED;
    return "";
}
