
#include "FileManager.hpp"
#include "Tools.hpp"

#ifdef MAC_OS
#include "CallObj.h"
#endif

const string FileManager::assetsDirectory() {
    
#ifdef MAC_OS
    return workDirectory() + string("/Assets/");
#endif
    
    return "../../../../Assets/";
}

const string FileManager::workDirectory() {
    
#ifdef WINDOWS
	char result[MAX_PATH];
	return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
#endif

    return "";
}
