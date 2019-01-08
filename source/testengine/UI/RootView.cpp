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

using namespace te;

static ui::Window* new_view = nullptr;
static ui::ImageView* new_image_view = nullptr;
static ui::Label* new_label = nullptr;

void RootView::_setup() {
    new_view = new ui::Window({ 100, 300, 200, 200 });
    new_view->color = ui::Color::black;

    new_image_view = new ui::ImageView({ 50, 50, 50, 50 }, new ui::Image(Paths::images_directory() + "cat.jpg"));
    new_image_view->set_content_mode(ui::ImageView::ContentMode::AspectFit);

    new_label = new ui::Label({ 5, 5, 100, 20 });
    new_label->set_text("Helloff");

    new_view->add_subview(new_image_view);
    new_view->add_subview(new_label);

    add_subview(new_view);
}

void RootView::_draw() {
    ui::View::_draw();
}
