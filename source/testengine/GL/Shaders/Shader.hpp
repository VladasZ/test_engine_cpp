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
#include "Rect.hpp"

class Window;

class Shader {
    
    Shader() = default;
    Shader(const std::string &vertexPath, const std::string &fragmentPath);
        
    friend Window;
    
    int program = -1;
    
    int uniformColor = -1;
    int viewportTranslation = -1;
    int uniformPosition = -1;
    int transform = -1;
	int mvpMatrix = -1;
    
    static void initialize();
    
public:
    
    static Shader ui;
    static Shader uiTexture;
    static Shader uiMonochrome;
    static Shader uiPath;
    static Shader sprite;
    
    static Shader simple3D;
    static Shader colored3D;

    void use() const;
	int getProgramID() const { return program; }

    void setUniformColor(const ui::Color& color);
	void setMVPMatrix(const Matrix4& mvp);
    void setUniformPosition(float x, float y);
};
