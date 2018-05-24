#pragma once

class ShaderCompiler {
    
    ShaderCompiler();
    
private:
    
    static String shaderVersion();
    
public:
    
    static int compile(const String &vertexPath, const String &fragmentPath);
};

