//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/8/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "Input.hpp"
#include "RootView.hpp"

using namespace te;
using namespace ui;

void RootView::_setup() {
    background_color = gm::Color::clear;

#ifdef DRAW_TOUCHES
    Input::on_touch.subscribe([&](Touch* touch) {
        auto view = View::dummy({ 5, 5 });
        view->set_center(touch->location);
        add_subview(view);
    });
#endif

}

void RootView::_layout() {
    _calculate_absolute_frame();
    _layout_subviews();
}
