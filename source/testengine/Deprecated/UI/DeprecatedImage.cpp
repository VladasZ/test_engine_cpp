//
//  Image.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "DeprecatedImage.hpp"
#include "GL.hpp"
#include "SOIL.h"
#include "Shader.hpp"
#include "Debug.hpp"
#include "Paths.hpp"
#include "Image.hpp"

DeprecatedImage* DeprecatedImage::cat;
DeprecatedImage* DeprecatedImage::slow;
DeprecatedImage* DeprecatedImage::palm;
DeprecatedImage* DeprecatedImage::frisk;
DeprecatedImage* DeprecatedImage::fullHD;
DeprecatedImage* DeprecatedImage::text;
DeprecatedImage* DeprecatedImage::square;

DeprecatedImage* DeprecatedImage::up;
DeprecatedImage* DeprecatedImage::down;
DeprecatedImage* DeprecatedImage::left;
DeprecatedImage* DeprecatedImage::right;


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

void DeprecatedImage::init(const ui::Size& size, const void* data, int channels, int filter) {

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

	set_filter((Filter)filter);

	GL(glBindTexture(GL_TEXTURE_2D, 0));
}

DeprecatedImage::DeprecatedImage(const ui::Size& size, int channels, Filter filter) {
	init(size, nullptr, channels, filter);
}

DeprecatedImage::DeprecatedImage(const ui::Size& size, const void* data, int channels, Filter filter) {
	init(size, data, channels, filter);
}

DeprecatedImage::DeprecatedImage(const std::string& file, Filter filter) {

	ui::Image image(Paths::assets_directory() + "Images/" + file);

#if IMAGES_LOADING_OUTPUT
	Log("Loading image: " << file << " channels: " << channels);
#endif
	init(image.size(), image.data(), image.channels(), filter);
}

DeprecatedImage::~DeprecatedImage() {
	unbind();
	glDeleteTextures(1, &_id);
}

void DeprecatedImage::bind() const {
	GL(glBindTexture(GL_TEXTURE_2D, _id));
}

void DeprecatedImage::unbind() const {
	GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void DeprecatedImage::initialize() {
	cat    = new DeprecatedImage("cat.jpg");
	slow   = new DeprecatedImage("slow.jpg");
	palm   = new DeprecatedImage("palm.png");
	frisk  = new DeprecatedImage("frisk.png");
	fullHD = new DeprecatedImage("fullHD.jpg");
    text   = new DeprecatedImage("text.png");
    square = new DeprecatedImage("square.png");
    
    up     = new DeprecatedImage("up.png");
    down   = new DeprecatedImage("down.png");
    left   = new DeprecatedImage("left.png");
    right  = new DeprecatedImage("right.png");

}

void DeprecatedImage::set_filter(Filter filter) {
	switch (filter) {
	case Nearest:
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
		break;
	case Linear:
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		break;
	case Bilinear:
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST));
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		break;
	case Trilinear:
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		break;
	default:
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	}
}

bool DeprecatedImage::is_monochrome() const { return channels == 1; }
