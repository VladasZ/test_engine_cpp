//
//  TestSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestSlidersView.hpp"

static const float width  = 400;
static const float height = 280;
static const float margin = 5;

TestSlidersView TestSlidersView::view = TestSlidersView({ 0, 0, width, height });

void TestSlidersView::_setup() {

    _rotation_view = new Vec4SlidersView({ 0, 0, 168, height });
    add_subview(_rotation_view);



}
