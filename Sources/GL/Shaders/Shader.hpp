//
//  Shader.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"

class Window;

class Shader MEMORY_MANAGED(Shader) {
    
    Shader() = default;
    Shader(const String &vertexPath, const String &fragmentPath);
    
    static void setupUiTranslation();
    
    friend Window;
    
public:
    
    static Shader ui;
    static Shader uiTexture;
    static Shader uiMonochrome;
    static Shader sprite;

    static void initialize();
    
    int program = -1;
    
    int uniformColor = -1;
    int uniformProjection = -1;
    int uniformPosition = -1;

    void use() const;
    void setUniformColor(const Color &color);
    void setUniformProjectionMatrix(const mat4 &projection);
    void setUniformPosition(float x, float y);
};
