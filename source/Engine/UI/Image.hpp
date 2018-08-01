//
//  Image.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "NonCopyable.hpp"

class FrameBuffer;

class UIImage : public NonCopyable {
    
	unsigned int _id = 0;
    
    void init(const Size &size, void* data, int channels, int filter);
    
	UIImage() = default;
    
public:
    
    enum Filter {
        Nearest,
        Linear,
        Bilinear,
        Trilinear,
        Default = Linear
    };
    
    static UIImage* cat;
    static UIImage* slow;
    static UIImage* palm;
    static UIImage* frisk;

    static void initialize();
  
    Size size;
    int channels;
    
	UIImage(const Size &size, int channels = 4, Filter filter = Filter::Default);
	UIImage(const Size &size, void* data, int channels, Filter filter = Filter::Default);
	UIImage(const std::string &file, Filter filter = Filter::Default);
    ~UIImage();

	const unsigned int& _get_GL_id() { return _id; }

    void bind() const;
    void unbind() const;
    
    void setFilter(Filter filter);
    
    bool isMonochrome() const;
};

using Image = UIImage;
