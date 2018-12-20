//
//  Image.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "View.hpp"
#include "Image.hpp"
#include "NonCopyable.hpp"

class FrameBuffer;

class Image : public ui::Image, public NonCopyable {

	GLuint _id = 0;

	void _init(int filter);

public:

	enum Filter {
		Nearest,
		Linear,
		Bilinear,
		Trilinear,
		Default = Linear
	};

	Image(const ui::Size& size, int channels = 4, Filter filter = Filter::Default); // REMOVE
	Image(const ui::Size& size, void* data, int channels, Filter filter = Filter::Default);
	Image(const std::string& file, Filter filter = Filter::Default);
    ~Image() override;

	GLuint &_get_GL_id() { return _id; }

	void bind() const;
	void unbind() const;

	void draw_in_rect(const ui::Rect& rect) override;

public:

	static Image* cat;
	static Image* slow;
	static Image* palm;
	static Image* frisk;
	static Image* fullHD;
	static Image* text;
	static Image* square;

	static Image* up;
	static Image* down;
	static Image* left;
	static Image* right;

	static Image* mouse_pointer;
	static Image* rb_cursor;
	static Image* rl_cursor;
	static Image* rt_cursor;
	static Image* tb_cursor;

	static void initialize();

private:

	void _set_filter(Filter filter);

};
