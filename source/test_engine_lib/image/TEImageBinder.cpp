//
//  TEImageBinder.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Debug.hpp"
#include "Image.hpp"
#include "TEImageBinder.hpp"

static unsigned int mode_for_channels(int channels) {
//    switch (channels) {
//#ifdef IOS
//    case 1: return GL_LUMINANCE;
//#else
//    case 1: return GL_RED;
//#endif
//    default: return GL_RGBA;
//    }
    return 1;
}

TEImageBinder::TEImageBinder(Image* image) {

//    GL(glGenTextures(1, &_id));

//    bind();

//    if (image->channels() == 1)
//        GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

//    GL(glTexImage2D(GL_TEXTURE_2D,
//        0,
//        static_cast<GLint>(mode_for_channels(image->channels())),
//        static_cast<GLsizei>(image->width()),
//        static_cast<GLsizei>(image->height()),
//        0,
//        mode_for_channels(image->channels()),
//        GL_UNSIGNED_BYTE,
//        image->data()));

//    GL(glGenerateMipmap(GL_TEXTURE_2D));

//    _set_filter(static_cast<Filter>(Filter::Default));

//    unbind();
}

TEImageBinder::~TEImageBinder() {
    unbind();
   // GL(glDeleteTextures(1, &_id));
}

void TEImageBinder::bind() const {
    //GL(glBindTexture(GL_TEXTURE_2D, _id));
}
void TEImageBinder::unbind() const {
    //GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void TEImageBinder::_set_filter(Filter filter) {
//    switch (filter) {
//    case Nearest:
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
//        break;
//    case Linear:
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
//        break;
//    case Bilinear:
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST));
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
//        break;
//    case Trilinear:
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
//        GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
//        break;
//    }
}
