//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/8/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "Window.hpp"
#include "ImageView.hpp"
#include "Label.hpp"
#include "Paths.hpp"
#include "StackView.hpp"

using namespace te;

static ui::Window* new_view = nullptr;
static ui::ImageView* new_image_view = nullptr;
static ui::Label* new_label = nullptr;
static ui::StackView* stack_view = nullptr;

static ui::View* lt = nullptr;
static ui::View* rt = nullptr;
static ui::View* lb = nullptr;
static ui::View* rb = nullptr;

void RootView::_setup() {
    new_view = new ui::Window({ 100, 300, 200, 200 });
    new_view->color = ui::Color::black;

    new_image_view = new ui::ImageView({ 50, 50, 50, 50 }, new ui::Image(Paths::images_directory() + "cat.jpg"));
    new_image_view->set_content_mode(ui::ImageView::ContentMode::AspectFit);

    new_label = new ui::Label({ 5, 5, 100, 20 });
    new_label->set_text("Helloff");

    new_view->add_subview(new_image_view);
    new_view->add_subview(new_label);

    stack_view = new ui::StackView({ 100, 100 });
    stack_view->color = ui::Color::green;

    lt = new ui::View({ 100, 100 });
    rt = new ui::View({ 100, 100 });
    lb = new ui::View({ 100, 100 });
    rb = new ui::View({ 100, 100 });

    add_subview(new_view);
    add_subview(stack_view);

    for (auto& view : { lt, rt, lb, rb }) {
        view->color = ui::Color::turquoise;
        add_subview(view);
    }
}

void RootView::_draw() {
    ui::View::_draw();
}

void RootView::_layout() {
    _calculate_absolute_frame();

    stack_view->edit_frame([&](ui::Rect& frame) {
        frame.size.height = this->_frame.size.height;
    });

    rt->edit_frame([&](ui::Rect& frame) {
        frame.origin.x = this->_frame.size.width - 100;
    });

    lb->edit_frame([&](ui::Rect& frame) {
        frame.origin.y = this->_frame.size.height - 100;
    });

    rb->edit_frame([&](ui::Rect& frame) {
        frame.origin.x = this->_frame.size.width - 100;
        frame.origin.y = this->_frame.size.height - 100;
    });

    _layout_subviews();
}
