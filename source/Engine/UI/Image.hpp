//
//  Image.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "Size.hpp"
#include "NonCopyable.hpp"
#include "MemoryManaged.hpp"

class Image : public NonCopyable _MEMORY_MANAGED(Image) {
    
    GLuint id = 0;
    
    void init(const Size &size, void *data, const int &channels, int filter);
    
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
    static Image *frisk;

    static void initialize();
  
    Size size;
    int channels;
    
    Image(const Size &size, void *data, const int &channels, Filter filter = Filter::Linear);
    Image(const std::string& file, Filter filter = Filter::Linear);
    
    void bind() const;
    void unbind() const;
    
    void setFilter(Filter filter);
    
    bool isMonochrome() const;
};
