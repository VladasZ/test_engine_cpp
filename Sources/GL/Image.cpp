//
//  Image.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Image.hpp"
#include "SOIL.h"
#include "Shader.hpp"

Image *Image::cat;
Image *Image::slow;
Image *Image::palm;

static int modeForChannels(const int &channels) {
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

void Image::init(const Size &size, void *data, const int &channels, int filter) {
    
    this->channels = channels;
    this->size = size;
    
    SAFE(glGenTextures(1, &id));
    SAFE(glBindTexture(GL_TEXTURE_2D, id));
    //SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    //SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    //SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));// _MIPMAP_NEAREST));
    //SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    
    if (channels == 1)
        SAFE(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
    
    SAFE(glTexImage2D(GL_TEXTURE_2D,
                      0,
                      modeForChannels(channels),
                      size.width,
                      size.height,
                      0,
                      modeForChannels(channels),
                      GL_UNSIGNED_BYTE,
                      data));
    
    //glTexEnvf(GL_TEXTURE_2D,GL_TEXTURE_ENV_MODE,GL_MODULATE);
    
    
    SAFE(glGenerateMipmap(GL_TEXTURE_2D));
    
    setFilter((Filter)filter);
    
    SAFE(glBindTexture(GL_TEXTURE_2D, 0));
}

Image::Image(const Size &size, void *data, const int &channels, Filter filter) {
    init(size, data, channels, filter);
}

Image::Image(const string &file, Filter filter) {
    
    int width;
    int height;
    
    unsigned char *image = SOIL_load_image((FileManager::assetsDirectory() + "Images/" + file).c_str(),
                                           &width,
                                           &height,
                                           &channels,
                                           SOIL_LOAD_RGBA);
    
    size = Size(width, height);
    
    cout << "Loading image: " << file << " channels: " << channels << endl;
    init(size, image, channels, filter);
    SOIL_free_image_data(image);
}

void Image::bind() const {
    glBindTexture(GL_TEXTURE_2D, id);
    if (isMonochrome()) Shader::uiMonochrome.use();
    else                Shader::uiTexture.use();
}

void Image::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Image::initialize() {
    cat  = new Image("cat.jpg");
    slow = new Image("slow.jpg");
    palm = new Image("palm.png");
}

void Image::setFilter(Filter filter) {
    switch(filter) {
        case Nearest:
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
            break;
        case Linear:
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            break;
        case Bilinear:
            //CROSS_ASSERT(mip_maps, "Current texture does not have mip maps to apply this filter");
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST));
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            break;
        case Trilinear:
            //CROSS_ASSERT(mip_maps, "Current texture does not have mip maps to apply this filter");
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
            break;
        default:
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
            SAFE(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    }
}

bool Image::isMonochrome() const { return channels == 1; }
