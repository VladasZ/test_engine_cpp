#pragma once

#include "String.hpp"

class ShaderCompiler {
    
    ShaderCompiler();
    
private:
    
    static String shaderVersion();
    
public:
    
    static int compile(const String &vertexPath, const String &fragmentPath);
};

