//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/8/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "RootView.hpp"
#include "TestSlidersView.hpp"

using namespace te;

void RootView::_setup() {
    add_subview(&TestSlidersView::view);
}

void RootView::_draw() {
    ui::View::_draw();
}

void RootView::_layout() {
    _calculate_absolute_frame();
    _layout_subviews();
}
