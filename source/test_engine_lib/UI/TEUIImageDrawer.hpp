//
//  TEUIImageDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/23/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Rect.hpp"
#include "Image.hpp"
#include "UIImage.hpp"

class TEUIImageDrawer : public ui::UIImage::Drawer {

    unsigned int _id = 0;
    ui::UIImage* _ui_image;

public:

	enum Filter {
		Nearest,
		Linear,
		Bilinear,
		Trilinear,
		Default = Linear
	};

    TEUIImageDrawer(ui::UIImage*);
    ~TEUIImageDrawer() override;

    void draw_in_rect(const Rect&) override;

private:

	void _set_filter(Filter filter);

};
