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
#include "Color.hpp"

class Window;

class Shader {
    
    Shader() = default;
    Shader(const string &vertexPath, const string &fragmentPath);
    
    static void setupUiTranslation();
    
    friend Window;
    
public:
    
    static Shader simple;
    static Shader ui;
    static Shader colorVertices;
    static Shader texture;
    
    static void initialize();
    
    UInt program = -1;
    
    UInt uniformColor = -1;
    UInt uniformProjection = -1;
    
    void use() const;
    void setUniformColor(const Color &color) const;
    void setUniformProjectionMatrix(const mat4 &projection) const;
};
