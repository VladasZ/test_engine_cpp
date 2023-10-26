//
//  TEImageBinder.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Image.hpp"
#include "TEImageBinder.hpp"
#include "GLTextureLoader.hpp"


TEImageBinder::TEImageBinder(Image* image) {
    _id = gl::TextureLoader::load(image->data(), { image->width(), image->height() }, image->channels());
}

TEImageBinder::~TEImageBinder() {
    gl::TextureLoader::free(_id);
}

int TEImageBinder::id() const {
    return _id;
}

void TEImageBinder::bind() const {
    gl::TextureLoader::bind(_id);
}
