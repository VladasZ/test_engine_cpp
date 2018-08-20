//
//  Image.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "GL.hpp"
#include "NonCopyable.hpp"

class FrameBuffer;

class Image : public NonCopyable {

	GLuint _id = 0;

	void init(const Size &size, void* data, int channels, int filter);

	Image() = default;

public:

	enum Filter {
		Nearest,
		Linear,
		Bilinear,
		Trilinear,
		Default = Linear
	};

	static Image* cat;
	static Image* slow;
	static Image* palm;
	static Image* frisk;
	static Image* fullHD;
    static Image* text;
    static Image* square;

	static void initialize();

	Size size;
	int channels;

	Image(const Size &size, int channels = 4, Filter filter = Filter::Default);
	Image(const Size &size, void* data, int channels, Filter filter = Filter::Default);
	Image(const std::string &file, Filter filter = Filter::Default);
	~Image();

	GLuint &_get_GL_id() { return _id; }

	void bind() const;
	void unbind() const;

	void setFilter(Filter filter);

	bool isMonochrome() const;
};

using I = Image;
