#pragma once

#include "STL.hpp"

class FileManager {

public:

	static const string assetsDirectory();
    static const string workDirectory();
    
    static const string assetsPathWithFileName(const string& fileName);
};
