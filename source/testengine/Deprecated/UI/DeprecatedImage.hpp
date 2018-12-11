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

class DeprecatedImage : public NonCopyable {

	GLuint _id = 0;

	void init(const ui::Size& size, const void* data, int channels, int filter);

	DeprecatedImage() = default;

public:

	enum Filter {
		Nearest,
		Linear,
		Bilinear,
		Trilinear,
		Default = Linear
	};

	static DeprecatedImage* cat;
	static DeprecatedImage* slow;
	static DeprecatedImage* palm;
	static DeprecatedImage* frisk;
	static DeprecatedImage* fullHD;
    static DeprecatedImage* text;
    static DeprecatedImage* square;
    
    static DeprecatedImage* up;
    static DeprecatedImage* down;
    static DeprecatedImage* left;
    static DeprecatedImage* right;

	static void initialize();

	ui::Size size;
	int channels;

	DeprecatedImage(const ui::Size& size, int channels = 4, Filter filter = Filter::Default);
	DeprecatedImage(const ui::Size& size, const void* data, int channels, Filter filter = Filter::Default);
	DeprecatedImage(const std::string& file, Filter filter = Filter::Default);
	~DeprecatedImage();

	GLuint &_get_GL_id() { return _id; }

	void bind() const;
	void unbind() const;

	void set_filter(Filter filter);

	bool is_monochrome() const;
};
