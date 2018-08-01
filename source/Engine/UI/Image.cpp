//
//  UIImage.cpp
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

UIImage* UIImage::cat;
UIImage* UIImage::slow;
UIImage* UIImage::palm;
UIImage* UIImage::frisk;
 
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

void UIImage::init(const Size &size, void* data, int channels, int filter) {
    
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

UIImage::UIImage(const Size &size, int channels, Filter filter) {
    init(size, nullptr, channels, filter);
}

UIImage::UIImage(const Size &size, void* data, int channels, Filter filter) {
    init(size, data, channels, filter);
}

UIImage::UIImage(const std::string &file, Filter filter) {
    
    int width;
    int height;
    
    unsigned char* UIImage = SOIL_load_image((FileManager::assetsDirectory() + "UIImages/" + file).c_str(),
                                           &width,
                                           &height,
                                           &channels,
                                           SOIL_LOAD_RGBA);
        
#if IMAGES_LOADING_OUTPUT
    Log("Loading UIImage: " << file << " channels: " << channels);
#endif
    
    init(Size((float)width, (float)height), UIImage, channels, filter);
    SOIL_free_image_data(UIImage);
}

UIImage::~UIImage() {
    unbind();
    glDeleteTextures(1, &_id);
}

void UIImage::bind() const {
    GL(glBindTexture(GL_TEXTURE_2D, _id));
}

void UIImage::unbind() const {
    GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void UIImage::initialize() {
    cat   = new UIImage("cat.jpg");
    slow  = new UIImage("slow.jpg");
    palm  = new UIImage("palm.png");
    frisk = new UIImage("frisk.png");
}

void UIImage::setFilter(Filter filter) {
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

bool UIImage::isMonochrome() const { return channels == 1; }
