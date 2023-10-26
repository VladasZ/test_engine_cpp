//
//  TEUIDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Image.hpp"
#include "Assets.hpp"
#include "Buffer.hpp"
#include "PathData.hpp"
#include "GLWrapper.hpp"
#include "TEUIDrawer.hpp"

using namespace ui;
using namespace gm;
using namespace gl;


static void set_viewport(const Rect& rect) {
    GL::set_viewport(rect * GL::render_scale);
}

void TEUIDrawer::fill_rect(const Rect& rect, const Color& color) {
    set_viewport(rect);
    Assets::shaders->ui->use();
    Assets::shaders->ui->set_color(color);
    Assets::buffers->fullscreen->draw();
}

void TEUIDrawer::draw_rect(const Rect& rect, const Color& color) {
    set_viewport(rect);
    Assets::shaders->ui->use();
    Assets::shaders->ui->set_color(color);
    Assets::buffers->fullscreen_outline->draw();
}

void TEUIDrawer::draw_image_in_rect(Image* image, const Rect& rect, const gm::Color& color) {
    if (rect.size.is_negative()) return;

    if (image->is_monochrome()) {
        Assets::shaders->ui_monochrome->use();
        Assets::shaders->ui_monochrome->set_color(color);
    }
    else {
        Assets::shaders->ui_texture->use();
    }

    set_viewport(rect);
    image->bind();
    Assets::buffers->fullscreen_image->draw();
}

void TEUIDrawer::draw_path_in_rect(ui::PathData* path, const gm::Rect& rect) {
    set_viewport(rect);
    Assets::shaders->ui_path->use();
    Assets::shaders->ui_path->set_color(path->color());
    Assets::shaders->ui_path->set_size(rect.size);
    static_cast<gl::Buffer*>(path->data())->draw_mode = GL::DrawMode::LineStrip;
    static_cast<gl::Buffer*>(path->data())->draw();
}

ui::PathData* TEUIDrawer::initialize_path_data(PointsPath* path, const Color& color, PathData::DrawMode draw_mode) {
    auto buffer = new gl::Buffer(gl::BufferConfiguration::_2, path->points());
    buffer->draw_mode = draw_mode == PathData::DrawMode::Outline ? GL::DrawMode::LineLoop : GL::DrawMode::TriangleFan;
    return new ui::PathData(path, buffer, color);
}

void TEUIDrawer::free_path_data(PathData* data) {
    delete static_cast<Buffer*>(data->data());
}

#ifdef DESKTOP_BUILD
void TEUIDrawer::set_cursor_mode(ui::Mouse::CursorMode cursor_mode) {
    switch (cursor_mode) {
        case Mouse::CursorMode::Arrow:
            GL::set_cursor_mode(GL::CursorMode::Arrow);
            break;
        case Mouse::CursorMode::Text:
            GL::set_cursor_mode(GL::CursorMode::Text);
            break;
        case Mouse::CursorMode::Drag:
            GL::set_cursor_mode(GL::CursorMode::Drag);
            break;
        case Mouse::CursorMode::HResize:
            GL::set_cursor_mode(GL::CursorMode::HResize);
            break;
        case Mouse::CursorMode::VResize:
            GL::set_cursor_mode(GL::CursorMode::VResize);
            break;
    }
}
#endif
