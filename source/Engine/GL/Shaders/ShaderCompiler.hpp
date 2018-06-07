#pragma once

#include <string>

class ShaderCompiler {
    
    ShaderCompiler();
    
private:
    
    static std::string shaderVersion();
    
public:
    
    static int compile(const std::string &vertexPath, const std::string &fragmentPath);
};

