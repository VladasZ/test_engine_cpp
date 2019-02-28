//
//  Shader.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <string>

#include    "Rect.hpp"
#include   "Color.hpp"
#include "Matrix4.hpp"

class Screen;

class Shader {
    
    Shader() = default;
    Shader(const std::string& name);
        
    friend Screen;
    
    unsigned int _program = 0;
    
    int _uniform_color       ;
    int _viewport_translation;
    int _uniform_position    ;
    int _transform           ;
    int _mvp_matrix          ;
    int _model_matrix        ;
    int _light_position      ;
    
    static void initialize();
    
public:
    
    static Shader* ui           ;
    static Shader* ui_texture   ;
    static Shader* ui_monochrome;
    
    static Shader*   simple3D;
    static Shader*  colored3D;
    static Shader* textured3D;

    static Shader* diffuse_colored;

    const std::string name;

    void use() const;

    unsigned int get_program_id() const;

    void set_uniform_color (const   Color&);
    void set_mvp_matrix    (const Matrix4&);
    void set_model_matrix  (const Matrix4&);
    void set_light_position(const Vector3&);
};
