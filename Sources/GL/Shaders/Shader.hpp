//
//  Shader.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "STL.hpp"
#include "Types.h"

class Shader {
    
    Shader() = default;
    Shader(const string &vertexPath, const string &fragmentPath);
    
public:
    
    static Shader simple;
    
    static void initialize();
    
    UInt program = -1;
    
    void use();
};
