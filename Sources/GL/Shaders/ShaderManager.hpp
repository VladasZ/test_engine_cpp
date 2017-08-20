#pragma once

#include "STL.hpp"
#include "Types.h"

class ShaderManager {
    
private:
    
    static string shaderVersion();
    
public:
    static UInt compileShaders();
    static UInt compileShaders(const string &vertexPath, const string &fragmentPath);
};

