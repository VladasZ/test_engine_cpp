//
//  Shader.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include "Color.hpp"
#include "GL.hpp"
#include "Rect.hpp"

class Screen;

class Shader {
    
    Shader() = default;
    Shader(const std::string& name);
        
    friend Screen;
    
    unsigned int _program = 0;
    
    int _uniform_color = -1;
    int _viewport_translation = -1;
    int _uniform_position = -1;
    int _transform = -1;
	int _mvp_matrix = -1;
    
    static void initialize();
    
public:
    
    static Shader ui;
    static Shader ui_texture;
    static Shader ui_monochrome;
    static Shader ui_path;
    static Shader sprite;
    
    static Shader simple3D;
    static Shader colored3D;

    void use() const;
	int get_program_id() const { return _program; }

    void set_uniform_color(const Color& color);
	void set_mvp_matrix(const Matrix4& mvp);
    void set_uniform_position(float x, float y);
};
