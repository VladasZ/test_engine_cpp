
#ifdef APPLE
#include "CallObj.h"
#elif WINDOWS
#include <Windows.h>
#endif

#include "Log.hpp"
#include "FileManager.hpp"

const std::string FileManager::assetsDirectory() {
#if WINDOWS
	return "../../../Assets/";
#else
	return "../../../../Assets/";
#endif
}

const std::string FileManager::workDirectory() {
#ifdef WINDOWS
	char result[MAX_PATH];
	return std::string(result, GetModuleFileName(NULL, result, MAX_PATH));
#endif
    NOT_IMPLEMENTED; return "";
}

const std::string FileManager::assetsPathWithFileName(const std::string& fileName) {
    return assetsDirectory() + fileName;
}
