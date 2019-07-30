//
//  TEUIDrawer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 12/15/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Image.hpp"
#include "Assets.hpp"
#include "Buffer.hpp"
#include "PathData.hpp"
#include "GLWrapper.hpp"
#include "TEUIDrawer.hpp"
#include "BufferData.hpp"

using namespace gm;

TEUIDrawer::TEUIDrawer() {

}

void TEUIDrawer::fill_rect(const Rect& rect, const Color& color) {
    GL::set_viewport(rect);
	Assets::shaders->ui->use();
	Assets::shaders->ui->set_uniform_color(color);
    Assets::buffers->fullscreen->draw();
}

void TEUIDrawer::draw_rect(const gm::Rect& rect, const gm::Color& color) {
    GL::set_viewport(rect);
	Assets::shaders->ui->use();
	Assets::shaders->ui->set_uniform_color(color);
    Assets::buffers->fullscreen_outline->draw();
}

void TEUIDrawer::draw_image_in_rect(Image* image, const Rect& rect) {
    if (rect.size.is_negative())
        return;

	if (image->is_monochrome())
         Assets::shaders->ui_monochrome->use();
	else
		Assets::shaders->ui_texture->use();

    GL::set_viewport(rect);
	image->bind();
    Assets::buffers->fullscreen_image->draw();
}

void TEUIDrawer::draw_path_in_rect(ui::PathData* path, const gm::Rect& rect) {
    GL::set_viewport(rect);
	Assets::shaders->ui->use();
	Assets::shaders->ui->set_uniform_color(path->color());
	Assets::shaders->ui->set_size(rect.size);
	static_cast<gl::Buffer*>(path->data())->draw();
}

ui::PathData* TEUIDrawer::initialize_path_data(gm::Path* path, const gm::Color& color) {
    return new ui::PathData(path, new gl::Buffer(path), color);
}

void TEUIDrawer::free_path_data(ui::PathData* data) {
    delete static_cast<gl::Buffer*>(data->data());
}

#ifdef DESKTOP_BUILD
void TEUIDrawer::set_cursor_mode(ui::Mouse::CursorMode cursor_mode) {
    switch (cursor_mode) {
    case ui::Mouse::CursorMode::Arrow:
        GL::set_cursor_mode(GL::CursorMode::Arrow);
        break;
    case ui::Mouse::CursorMode::Text:
        GL::set_cursor_mode(GL::CursorMode::Text);
        break;
    case ui::Mouse::CursorMode::Drag:
        GL::set_cursor_mode(GL::CursorMode::Drag);
        break;
    case ui::Mouse::CursorMode::HResize:
        GL::set_cursor_mode(GL::CursorMode::HResize);
        break;
    case ui::Mouse::CursorMode::VResize:
        GL::set_cursor_mode(GL::CursorMode::VResize);
        break;
    }
}
#endif
