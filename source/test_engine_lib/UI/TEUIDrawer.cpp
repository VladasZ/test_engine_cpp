//
//  TEUIDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "GL.hpp"
#include "Image.hpp"
#include "Buffer.hpp"
#include "TestEngine.hpp"
#include "TEUIDrawer.hpp"

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

void TEUIDrawer::fill_rect(const Rect& rect, const Color& color) {
    GL::set_viewport(rect);
    Shader::ui->use();
    Shader::ui->set_uniform_color(color);
    Buffer::fullscreen->bind();

    Buffer::fullscreen->draw();
}

void TEUIDrawer::draw_image_in_rect(Image* image, const Rect& rect) {
    if (rect.size.is_negative())
        return;

    image->bind();
    Buffer::fullscreen_image->bind();

    if (image->is_monochrome())
        Shader::ui_monochrome->use();
    else
        Shader::ui_texture->use();

    GL::set_viewport(rect);
    Buffer::fullscreen_image->draw();

    image->unbind();
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
