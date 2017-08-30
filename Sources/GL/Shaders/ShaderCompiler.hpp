#pragma once

#include "STL.hpp"
#include "Types.h"

class ShaderCompiler {
    
private:
    
    static string shaderVersion();
    
public:
    
    static UInt compile(const string &vertexPath, const string &fragmentPath);
};

