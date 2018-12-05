//
//  TestEngineDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "FrameBuffer.hpp"
#include "TestEngineDrawer.hpp"

TestEngineDrawer::TestEngineDrawer(FrameBuffer* frame_buffer) : _frame_buffer(frame_buffer) { }

void TestEngineDrawer::_draw_rect(const ui::Rect& rect) {
	_frame_buffer->draw([&] {
		GL::set_viewport(rect);
		Shader::ui.use();
		Shader::ui.set_uniform_color(ui::Color::green);
		Buffer::fullscreen->draw();
	});
}

void TestEngineDrawer::_fill_rect(const ui::Rect& rect, const ui::Color& color) {

}

const ui::Rect TestEngineDrawer::_convert_rect(const ui::Rect& rect) {
	return rect;
}