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
#include "Types.h"

class Image {
    
    GLuint id = 0;
    
    void init(const UInt &width, const UInt &height, void *data, const UInt &channels);
    
    Image() = default;
    
public:
    
    static Image *cat;
    static Image *slow;
    static Image *test;

    static void initialize();
  
    int width, height;
    const bool monochrome;
    
    Image(const UInt &width, const UInt &height, void *data, const UInt &channels = 4);
    Image(const string& file);
    
    void bind() const;
    void unbind() const;
};
