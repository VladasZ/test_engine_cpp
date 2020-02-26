//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Assets.hpp"
#include "TestView.hpp"

using namespace ui;

void te::TestView::_setup() {

    ScrollView::_setup();

    init_view(view,       { 100, 100 });
    init_view(label,      { 100, 100 });
    init_view(button,     { 100, 100 });
    init_view(image_view, { 100, 100 });

    view->background_color = gm::Color::random();
    label->set_text("Text");
    button->on_press = [&] { button->background_color = gm::Color::random(); };
    image_view->set_image(Assets::images->cat);

}

void te::TestView::_layout() {
    _calculate_absolute_frame();

    view->place_tr(30);
    label->place_at_center();
    button->place_br(30);
    image_view->place_bl();

    _layout_subviews();

    ScrollView::_layout();
}
