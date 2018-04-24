//
//  Shader.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "GL.hpp"

class Window;

class Shader MEMORY_MANAGED(Shader) {
    
    Shader() = default;
    Shader(const String &vertexPath, const String &fragmentPath);
    
    static void setupUiTranslation();
    
    friend Window;
    
    int program = -1;
    
    int uniformColor = -1;
    int uiTranslation = -1;
    int uniformPosition = -1;
    int transform = -1;
    
    static void initialize();
    
public:
    
    static Shader ui;
    static Shader uiTexture;
    static Shader uiMonochrome;
    static Shader sprite;

    void use() const;
    void setUniformColor(const Color &color);
    void setUITranslationMatrix(const mat4 &projection);
    void setTransformMatrix(const mat4 &transform);
    void setUniformPosition(float x, float y);
};
