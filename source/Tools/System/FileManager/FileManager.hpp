#pragma once

#include "String.hpp"

class FileManager {
    
    FileManager();

public:

	static const String assetsDirectory();
    static const String workDirectory();
    
    static const String assetsPathWithFileName(const String& fileName);
};
