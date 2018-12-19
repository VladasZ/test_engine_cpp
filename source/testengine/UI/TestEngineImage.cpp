//
//  Image.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "TestEngineDrawer.hpp"

#include "TestEngineImage.hpp"
#include "GL.hpp"
#include "SOIL.h"
#include "Shader.hpp"
#include "Debug.hpp"
#include "Paths.hpp"
#include "Image.hpp"
#include "Buffer.hpp"
#include "Screen.hpp"
#include "FrameBuffer.hpp"

Image* Image::cat;
Image* Image::slow;
Image* Image::palm;
Image* Image::frisk;
Image* Image::fullHD;
Image* Image::text;
Image* Image::square;

Image* Image::up;
Image* Image::down;
Image* Image::left;
Image* Image::right;

Image* Image::mouse_pointer;
Image* Image::rb_cursor;
Image* Image::rl_cursor;
Image* Image::rt_cursor;
Image* Image::tb_cursor;


static int modeForChannels(int channels) {
	switch (channels) {
#ifdef IOS
    case 1: return GL_LUMINANCE;
#else
    case 1: return GL_RED;
#endif
        //case 3:  return GL_RGBA;
        //case 4:  return GL_RGBA;
    default: return GL_RGBA;
	}
}

void Image::_init(int filter) {

	GL(glGenTextures(1, &_id));
	GL(glBindTexture(GL_TEXTURE_2D, _id));

	if (_channels == 1)
		GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

	GL(glTexImage2D(GL_TEXTURE_2D,
		0,
		modeForChannels(_channels),
		(GLsizei)_size.width,
		(GLsizei)_size.height,
		0,
		modeForChannels(_channels),
		GL_UNSIGNED_BYTE,
		_data));

	GL(glGenerateMipmap(GL_TEXTURE_2D));

	_set_filter((Filter)filter);

	GL(glBindTexture(GL_TEXTURE_2D, 0));
}

Image::Image(const ui::Size& size, int channels, Filter filter)
	:
	ui::Image(size, nullptr, channels)
{
	_init(filter);
}

Image::Image(const ui::Size& size, void* data, int channels, Filter filter)
	:
	ui::Image(size, data, channels)
{
	_init(filter);
}

Image::Image(const std::string& file, Filter filter) 
	: 
	ui::Image(Paths::assets_directory() + "Images/" + file) 
{

#if IMAGES_LOADING_OUTPUT
	Log("Loading image: " << file << " channels: " << channels);
#endif
	_init(filter);
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
  cat           = new Image("cat.jpg");
  slow          = new Image("slow.jpg");
  palm          = new Image("palm.png");
  frisk         = new Image("frisk.png");
  fullHD        = new Image("fullHD.jpg");
  text          = new Image("text.png");
  square        = new Image("square.png");
    
  up            = new Image("up.png");
  down          = new Image("down.png");
  left          = new Image("left.png");
  right         = new Image("right.png");

  mouse_pointer = new Image("cursors/mouse_pointer.png");
  rb_cursor     = new Image("cursors/rb_cursor.png");
  rl_cursor     = new Image("cursors/rl_cursor.png");
  rt_cursor     = new Image("cursors/rt_cursor.png");
  tb_cursor     = new Image("cursors/tb_cursor.png");
}

void Image::draw_in_rect(const ui::Rect& rect) {
    Screen::root_frame_buffer->draw([&] {
		this->bind();
		if (this->is_monochrome()) Shader::ui_monochrome.use();
		else                       Shader::ui_texture.use();
		GL::set_viewport(rect);
		Buffer::fullscreen_image->draw();
		this->unbind();
	});
}

void Image::_set_filter(Filter filter) {
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
	}
}
