//
//  TestEngineDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Screen.hpp"
#include "FrameBuffer.hpp"
#include "TestEngineDrawer.hpp"

void TestEngineDrawer::_draw_rect(const ui::Rect& rect) {
    Screen::root_frame_buffer->draw([&] {
		GL::set_viewport(rect);
		Shader::ui.use();
		Shader::ui.set_uniform_color(ui::Color::green);
		Buffer::fullscreen->draw();
	});
}

void TestEngineDrawer::_fill_rect(const ui::Rect& rect, const ui::Color& color) {
    Screen::root_frame_buffer->draw([&] {
		GL::set_viewport(rect);
		Shader::ui.use();
		Shader::ui.set_uniform_color(color);
		Buffer::fullscreen->draw();
	});
}

//void TestEngineDrawer::_set_cursor_mode(ui::CursorMode cursor_mode) {
//    Window::set_cursor_mode(cursor_mode);
//}

const ui::Rect TestEngineDrawer::_convert_rect(const ui::Rect& rect) {
	return rect;
}
