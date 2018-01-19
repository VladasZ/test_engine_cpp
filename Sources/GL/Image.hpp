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
    
    GLuint id = 0;
    
    void init(const int &width, const int &height, void *data, const int &channels, int filter);
    
    Image() = default;
    
public:
    
    enum Filter {
        Nearest,
        Linear,
        Bilinear,
        Trilinear
    };
    
    static Image *cat;
    static Image *slow;
    static Image *palm;

    static void initialize();
  
    int width, height;
    int channels;
    
    Image(const int &width, const int &height, void *data, const int &channels, Filter filter = Filter::Linear);
    Image(const string& file, Filter filter = Filter::Linear);
    
    void bind() const;
    void unbind() const;
    
    void setFilter(Filter filter);
    
    bool isMonochrome() const;
};
