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

Image Image::cat;
Image Image::slow;
Image Image::test;

Image::Image(const string &file) {
    
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int channels;
    
    unsigned char *image = SOIL_load_image((FileManager::assetsDirectory() + "Images/" + file).c_str(),
                                           &width,
                                           &height,
                                           &channels,
                                           SOIL_LOAD_RGBA);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Image::bind() const {
    
    glBindTexture(GL_TEXTURE_2D, id);
}

void Image::unbind() const {
    
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Image::initialize() {
    
    cat  = Image("cat.jpg");
    slow = Image("slow.jpg");
    test = Image("test.png");
}
