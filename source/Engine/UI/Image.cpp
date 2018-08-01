//
//  Image.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Image.hpp"
#include "GL.hpp"
#include "SOIL.h"
#include "Shader.hpp"
#include "Debug.hpp"
#include "FileManager.hpp"

Image* Image::cat;
Image* Image::slow;
Image* Image::palm;
Image* Image::frisk;

static int modeForChannels(int channels) {
    switch (channels) {
#if IOS
        case 1: return GL_LUMINANCE;  break;
#else
        case 1: return GL_RED;  break;
#endif
        //case 3:  return GL_RGBA; break;
        //case 4:  return GL_RGBA; break;
        default: return GL_RGBA; break;
    }
}

void Image::init(const Size &size, void* data, int channels, int filter) {
    
    this->channels = channels;
    this->size = size;
    
    GL(glGenTextures(1, &_id));
    GL(glBindTexture(GL_TEXTURE_2D, _id));
    
    if (channels == 1)
        GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
    
    GL(glTexImage2D(GL_TEXTURE_2D,
                      0,
                      modeForChannels(channels),
                      (GLsizei)size.width,
					  (GLsizei)size.height,
                      0,
                      modeForChannels(channels),
                      GL_UNSIGNED_BYTE,
                      data));    
    
    GL(glGenerateMipmap(GL_TEXTURE_2D));
    
    setFilter((Filter)filter);
    
    GL(glBindTexture(GL_TEXTURE_2D, 0));
}

Image::Image(const Size &size, int channels, Filter filter) {
    init(size, nullptr, channels, filter);
}

Image::Image(const Size &size, void* data, int channels, Filter filter) {
    init(size, data, channels, filter);
}

Image::Image(const std::string &file, Filter filter) {
    
    int width;
    int height;
    
    unsigned char* image = SOIL_load_image((FileManager::assetsDirectory() + "Images/" + file).c_str(),
                                           &width,
                                           &height,
                                           &channels,
                                           SOIL_LOAD_RGBA);
        
#if IMAGES_LOADING_OUTPUT
    Log("Loading image: " << file << " channels: " << channels);
#endif
    
    init(Size((float)width, (float)height), image, channels, filter);
    SOIL_free_image_data(image);
}

Image::~Image() {
    unbind();
    glDeleteTextures(1, &_id);
}

void Image::bind() const {
    GL(glBindTexture(GL_TEXTURE_2D, _id));
}

void Image::unbind() const {
    GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void Image::initialize() {
    cat   = new Image("cat.jpg");
    slow  = new Image("slow.jpg");
    palm  = new Image("palm.png");
    frisk = new Image("frisk.png");
}

void Image::setFilter(Filter filter) {
    switch(filter) {
        case Nearest:
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
            break;
        case Linear:
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            break;
        case Bilinear:
            //TEST_ASSERT(mip_maps, "Current texture does not have mip maps to apply this filter");
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST));
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            break;
        case Trilinear:
            //TEST_ASSERT(mip_maps, "Current texture does not have mip maps to apply this filter");
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            break;
        default:
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
            GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    }
}

bool Image::isMonochrome() const { return channels == 1; }
