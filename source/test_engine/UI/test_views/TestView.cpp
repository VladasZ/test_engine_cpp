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

    add_subview(view = new View());
    add_subview(label = new Label());
    add_subview(image_view = new ImageView(Assets::images->cat));

    view->edit_frame() = { 100, 100 };
    label->edit_frame() = { 100, 100 };
    image_view->edit_frame() = { 100, 100 };

    label->set_text("Text");

   // enable_resize();

}

void te::TestView::_layout() {
    _calculate_absolute_frame();

    view->place_tr();
    label->place_br();
    image_view->place_bl();

    _layout_subviews();

    ScrollView::_layout();
}
