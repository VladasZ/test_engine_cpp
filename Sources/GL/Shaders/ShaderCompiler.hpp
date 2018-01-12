#pragma once

#include "STL.hpp"

class ShaderCompiler {
    
private:
    
    static string shaderVersion();
    
public:
    
    static int compile(const string &vertexPath, const string &fragmentPath);
};

