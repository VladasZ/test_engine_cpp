

#ifdef APPLE
#include "CallObj.h"
#elif WINDOWS
#include <Windows.h>
#endif

const String FileManager::assetsDirectory() {
    
#ifdef APPLE
    return String(workDirectoryPath()) + String("/Assets/");
#endif
    
#ifdef WINDOWS
    return "../../../../Assets/";
#endif
    
    //NOT_IMPLEMENTED;
    return "";
}

const String FileManager::workDirectory() {
    
#ifdef WINDOWS
	char result[MAX_PATH];
	return std::String(result, GetModuleFileName(NULL, result, MAX_PATH));
#endif

    //NOT_IMPLEMENTED;
    return "";
}

const String FileManager::assetsPathWithFileName(const String& fileName) {
    
    return assetsDirectory() + fileName;
}

