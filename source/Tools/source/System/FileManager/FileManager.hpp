#pragma once

#include "String.hpp"

class FileManager {
    
    FileManager();

public:

	static const std::string assetsDirectory();
    static const std::string workDirectory();
    
    static const std::string assetsPathWithFileName(const std::string& fileName);
};
