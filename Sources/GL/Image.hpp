//
//  Image.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "STL.hpp"
#include "GL.hpp"

class Image {
    
    GLuint id;
    
    Image() = default;
    
public:
    
    static Image cat;
    static Image slow;
    static Image test;

    static void initialize();
  
    int width, height;
    
    Image(const string& file);
    
    void bind() const;
    void unbind() const;
};
