#pragma once

#include <string>

class ShaderCompiler {
    
    ShaderCompiler();
    
private:
    
    static std::string shader_version();
    
public:
    
    static int compile(const std::string& vertex_path, const std::string& fragment_path);
};

