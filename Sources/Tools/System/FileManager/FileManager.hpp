#pragma once

class FileManager {
    
    FileManager();

public:

	static const string assetsDirectory();
    static const string workDirectory();
    
    static const string assetsPathWithFileName(const string& fileName);
};
