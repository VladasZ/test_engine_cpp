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

void RootView::_setup() {
    new_view = new ui::Window({ 100, 100, 200, 200 });
    new_view->color = ui::Color::black;

    new_image_view = new ui::ImageView({ 50, 50, 50, 50 }, new ui::Image(Paths::images_directory() + "cat.jpg"));
    new_image_view->set_content_mode(ui::ImageView::ContentMode::AspectFit);

    new_label = new ui::Label({ 5, 5, 100, 20 });
    new_label->set_text("Helloff");

    new_view->add_subview(new_image_view);
    new_view->add_subview(new_label);

    stack_view = new ui::StackView({ 100, 100 });
    stack_view->color = ui::Color::green;

    for (int i = 0; i < 5; i++) {
        auto label = new ui::Label({ 100, 20 });
        label->set_text(std::string() + "hello" + std::to_string(i));
        stack_view->add_subview(ui::View::dummy());
        stack_view->add_subview(label);
    }

    add_subview(new_view);
    add_subview(stack_view);
}

void RootView::_draw() {
    ui::View::_draw();
}

void RootView::_layout() {
    _calculate_absolute_frame();

    stack_view->edit_frame([&](ui::Rect& frame) {
        frame.size.height = this->_frame.size.height;
        frame.origin.x = _frame.size.width - frame.size.width;
    });

    _layout_subviews();
}
