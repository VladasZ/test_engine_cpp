//
//  TEImageDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "ui.hpp"

#include "GL.hpp"
#include "Shader.hpp"
#include "Debug.hpp"
#include "Paths.hpp"
#include "Image.hpp"
#include "Buffer.hpp"
#include "Screen.hpp"
#include "TEUIDrawer.hpp"
#include "TEImageDrawer.hpp"

static unsigned int mode_for_channels(int channels) {
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

TEImageDrawer::TEImageDrawer(ui::Image* image) : _ui_image(image) {

    GL(glGenTextures(1, &_id));
    GL(glBindTexture(GL_TEXTURE_2D, _id));

    if (_ui_image->channels() == 1)
        GL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

    GL(glTexImage2D(GL_TEXTURE_2D,
        0,
        static_cast<GLint>(mode_for_channels(_ui_image->channels())),
        static_cast<GLsizei>(_ui_image->size().width),
        static_cast<GLsizei>(_ui_image->size().height),
        0,
        mode_for_channels(_ui_image->channels()),
        GL_UNSIGNED_BYTE,
        _ui_image->data()));

    GL(glGenerateMipmap(GL_TEXTURE_2D));

    _set_filter(static_cast<Filter>(Filter::Default));

    GL(glBindTexture(GL_TEXTURE_2D, 0));
}

TEImageDrawer::~TEImageDrawer() {
    GL(glDeleteTextures(1, &_id));
    GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void TEImageDrawer::draw_in_rect(const Rect& rect) {

    if (rect.size.is_negative())
        return;

    GL(glBindTexture(GL_TEXTURE_2D, _id));

    if (this->_ui_image->is_monochrome())
        Shader::ui_monochrome.use();
    else
        Shader::ui_texture.use();

    GL::set_viewport(rect);
    Buffer::fullscreen_image->draw();
    GL(glBindTexture(GL_TEXTURE_2D, 0));
}

void TEImageDrawer::_set_filter(Filter filter) {
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
