
//  Image.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "TestEngineDrawer.hpp"

#include "TestEngineImage.hpp"
#include "GL.hpp"
#include "SOIL.h"
#include "Shader.hpp"
#include "Debug.hpp"
#include "Paths.hpp"
#include "Image.hpp"
#include "Buffer.hpp"
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

  mouse_pointer = new Image("mouse_pointer.png");
}

void Image::draw_in_rect(const ui::Rect& rect) {
	auto frame_buffer = static_cast<TestEngineDrawer*>(ui::config::drawer())->frame_buffer();

	frame_buffer->draw([&] {
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
	default:
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL(glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
	}
}

Image* Image::for_edge(ui::View::Edge edge) {

	using Edge = ui::View::Edge;

	if (edge == Edge::Left)
		return Image::left;

	if (edge == Edge::Right)
		return Image::right;

	if (edge == Edge::Top)
		return Image::up;

	if (edge == Edge::Bottom)
		return Image::down;

	return Image::mouse_pointer;
}
