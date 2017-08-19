
#include "FileManager.hpp"
#include "Tools.hpp"

#ifdef MAC_OS
#include "CallObj.h"
#endif

const string FileManager::assetsDirectory() {
    
#ifdef MAC_OS
    return workDirectory() + string("/Assets/");
#endif
    
    Error("Not implemented");
    return "";
}

const string FileManager::workDirectory() {
    
    
    
    char buffer[10000];
    char *answer = getcwd(buffer, sizeof(buffer));
    string s_cwd;
    if (answer) { s_cwd = answer; }
    else { Error(""); }

    return s_cwd;
}
