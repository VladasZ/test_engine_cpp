//
//  TEUIDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "GL.hpp"
#include "Buffer.hpp"
#include "UIImage.hpp"
#include "TestEngine.hpp"
#include "TEUIDrawer.hpp"
#include "TEImageDrawer.hpp"

namespace cursor {
static GLFWcursor* arrow;
static GLFWcursor* text;
static GLFWcursor* drag;
static GLFWcursor* h_resize;
static GLFWcursor* v_resize;
}

TEUIDrawer::TEUIDrawer() {
    cursor::arrow    = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
    cursor::text     = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
#ifdef WIN32
    cursor::drag     = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
#else
	cursor::drag     = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
#endif
    cursor::h_resize = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
    cursor::v_resize = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
}

void TEUIDrawer::_fill_rect(const Rect& rect, const Color& color) {
    GL::set_viewport(rect);
    Shader::ui.use();
    Shader::ui.set_uniform_color(color);
    Buffer::fullscreen->draw();
}

const Rect TEUIDrawer::_convert_rect(const Rect& rect) {
    return rect;
}

ui::UIImage::Drawer* TEUIDrawer::init_image_drawer(ui::UIImage* image) {
    return new TEImageDrawer(image);
}

#ifdef UI_DESKTOP
void TEUIDrawer::set_cursor_mode(ui::Mouse::CursorMode cursor_mode) {
    switch (cursor_mode) {
    case ui::Mouse::CursorMode::Arrow:
        glfwSetCursor(TestEngine::screen.glfw_window, cursor::arrow);
        break;
    case ui::Mouse::CursorMode::Text:
        glfwSetCursor(TestEngine::screen.glfw_window, cursor::text);
        break;
    case ui::Mouse::CursorMode::Drag:
        glfwSetCursor(TestEngine::screen.glfw_window, cursor::drag);
        break;
    case ui::Mouse::CursorMode::HResize:
        glfwSetCursor(TestEngine::screen.glfw_window, cursor::h_resize);
        break;
    case ui::Mouse::CursorMode::VResize:
        glfwSetCursor(TestEngine::screen.glfw_window, cursor::v_resize);
        break;
    }
}
#endif
