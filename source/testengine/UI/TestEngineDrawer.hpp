//
//  TestEngineDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Drawer.hpp"

class TestEngineDrawer : public ui::Drawer {

public:

    TestEngineDrawer() = default;

private:

	void _draw_rect(const ui::Rect& rect) override;
	void _fill_rect(const ui::Rect& rect, const ui::Color& color) override;
   // void _set_cursor_mode(ui::CursorMode cursor_mode) override;
	const ui::Rect _convert_rect(const ui::Rect& rect) override;

};
