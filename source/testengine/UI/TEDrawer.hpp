//
//  TEDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Drawer.hpp"

namespace ui {
class Image;
}

class TestEngineDrawer : public ui::Drawer {

public:

    TestEngineDrawer();

private:

	void _draw_rect(const ui::Rect& rect) override;
	void _fill_rect(const ui::Rect& rect, const ui::Color& color) override;
	const ui::Rect _convert_rect(const ui::Rect& rect) override;

public:

    ui::Image::Drawer* init_image_drawer(ui::Image* image) override;

#ifdef UI_DESKTOP
    void set_cursor_mode(ui::Mouse::CursorMode cursor_mode) override;
#endif

};
