//
//  Image.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Image.hpp"

class TEImageDrawer : public ui::Image::Drawer {

    unsigned int _id = 0;
    ui::Image* _ui_image;

public:

	enum Filter {
		Nearest,
		Linear,
		Bilinear,
		Trilinear,
		Default = Linear
	};

    TEImageDrawer(ui::Image*);
    ~TEImageDrawer() override;

    void draw_in_rect(const Rect&) override;

private:

	void _set_filter(Filter filter);

};
