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

namespace cursor {
static GLFWcursor* arrow;
static GLFWcursor* text;
static GLFWcursor* drag;
static GLFWcursor* h_resize;
static GLFWcursor* v_resize;
}

TestEngineDrawer::TestEngineDrawer() {
    cursor::arrow    = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    cursor::text     = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
    cursor::drag     = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
    cursor::h_resize = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    cursor::v_resize = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
}

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

const ui::Rect TestEngineDrawer::_convert_rect(const ui::Rect& rect) {
    return rect;
}

#ifdef UI_DESKTOP
void TestEngineDrawer::_set_cursor_mode(ui::Mouse::CursorMode cursor_mode) {
    switch (cursor_mode) {
    case ui::Mouse::CursorMode::Arrow:
        glfwSetCursor(Screen::glfw_window, cursor::arrow);
        break;
    case ui::Mouse::CursorMode::Text:
        glfwSetCursor(Screen::glfw_window, cursor::text);
        break;
    case ui::Mouse::CursorMode::Drag:
        glfwSetCursor(Screen::glfw_window, cursor::drag);
        break;
    case ui::Mouse::CursorMode::HResize:
        glfwSetCursor(Screen::glfw_window, cursor::h_resize);
        break;
    case ui::Mouse::CursorMode::VResize:
        glfwSetCursor(Screen::glfw_window, cursor::v_resize);
        break;
    }
}
#endif
