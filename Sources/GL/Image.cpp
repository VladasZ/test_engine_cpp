//
//  Image.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Image.hpp"
#include "SOIL.h"
#include "FileManager.hpp"
#include "Log.hpp"
#include "Shader.hpp"

Image *Image::cat;
Image *Image::slow;
Image *Image::test;

void Image::init(const int &width, const int &height, void *data, const int &channels) {
    
    this->width = width;
    this->height = height;
    
    SAFE(glGenTextures(1, &id));
    SAFE(glBindTexture(GL_TEXTURE_2D, id));
//    SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
//    SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
    SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    SAFE(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    
    if (channels == 1) {
         //SAFE(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
         SAFE(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
    }
    else {
         SAFE(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data));
    }
    
     SAFE(glGenerateMipmap(GL_TEXTURE_2D));
     SAFE(glBindTexture(GL_TEXTURE_2D, 0));
}

Image::Image(const int &width, const int &height, void *data, const int &channels)
:
monochrome(channels == 1)
{
    init(width, height, data, channels);
}

Image::Image(const string &file)
:
monochrome(false)
{
    int channels;
    
    unsigned char *image = SOIL_load_image((FileManager::assetsDirectory() + "Images/" + file).c_str(),
                                           &width,
                                           &height,
                                           &channels,
                                           SOIL_LOAD_RGBA);
    init(width, height, image, channels);
    SOIL_free_image_data(image);
}

void Image::bind() const {
    
    glBindTexture(GL_TEXTURE_2D, id);
    
    if (monochrome) Shader::uiMonochrome.use();
    else Shader::uiTexture.use();
}

void Image::unbind() const {
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Image::initialize() {
    
    cat  = new Image("cat.jpg");
    slow = new Image("slow.jpg");
    test = new Image("test.png");
}
