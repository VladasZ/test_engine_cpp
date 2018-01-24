//
//  Color.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <glm.hpp>

using namespace glm;

class Color {
    
public:
    
    vec4 data;
    
    float &r;
    float &g;
    float &b;
    float &a;
    
    float *dataBuffer;
    
    Color(Color const &obj);
    Color& operator=(Color const &obj);
    
    Color();
    Color(float r, float g, float b, float a = 1);
    
    static Color random();
    
    Color withAlpha(float alpha) const;
    
    void setToUniform(int uniform) const;
    
    string toString() const;
    
    bool isTransparent() const;
    
    static const Color black;
    static const Color white;
    static const Color red;
    static const Color green;
    static const Color blue;
    static const Color yellow;
    static const Color orange;
    static const Color purple;
    static const Color turquoise;
    static const Color gray;
    static const Color clear;
};
