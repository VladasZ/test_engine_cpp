
#include "FileManager.hpp"

#ifdef APPLE
#include "CallObj.h"
#elif WINDOWS
#include <Windows.h>
#endif

const std::string FileManager::assetsDirectory() {
    
#ifdef APPLE
    return std::string(objCWorkDirectoryPath()) + "/Assets/";
#endif
    
#ifdef WINDOWS
    return "../Assets/";
#endif
    
    return "NOT_IMPLEMENTED";
}

const std::string FileManager::workDirectory() {
#ifdef WINDOWS
	char result[MAX_PATH];
	return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
#endif

    //NOT_IMPLEMENTED;
    return "";
}

const std::string FileManager::assetsPathWithFileName(const std::string& fileName) {
    
    return assetsDirectory() + fileName;
}

