//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/8/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "RootView.hpp"

using namespace gm;
using namespace te;

void RootView::_setup() {
    background_color = Color::clear;
}

void RootView::_draw() {
    ui::View::_draw();
}

void RootView::_layout() {
    _calculate_absolute_frame();
    _layout_subviews();
}
