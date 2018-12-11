//
//  TestEngineDrawer.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Drawer.hpp"

class FrameBuffer;

class TestEngineDrawer : public ui::Drawer {
	
	FrameBuffer* _frame_buffer = nullptr;

public:

	TestEngineDrawer() = delete;
	TestEngineDrawer(FrameBuffer* frame_buffer);

	const FrameBuffer* frame_buffer() const;

private:

	void _draw_rect(const ui::Rect& rect) override;
	void _fill_rect(const ui::Rect& rect, const ui::Color& color) override;
	const ui::Rect _convert_rect(const ui::Rect& rect) override;

};
