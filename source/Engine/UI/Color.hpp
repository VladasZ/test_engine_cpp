//
//  Color.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "String.hpp"
#include "Memory.hpp"

class Color MEMORY_MANAGED(Color) {
    
public:
        
    float r = 0;
    float g = 0;
    float b = 0;
    float a = 0;
        
    Color() = default;
    Color(Color const &obj);
    Color& operator=(Color const &obj);
    
    Color(float r, float g, float b, float a = 1);
    
    static Color random();
    
    Color withAlpha(float alpha) const;
    
    void setToUniform(int uniform) const;
    
    String toString() const;
    
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
    static const Color lightGray;
    static const Color clear;
};
