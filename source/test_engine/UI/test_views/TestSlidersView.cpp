//
//  TestSlidersView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TestSlidersView.hpp"

static const float _width  = 400;
static const float _height = 280;


TestSlidersView TestSlidersView::view = TestSlidersView({ 0, 0, _width, _height });

void TestSlidersView::setup() {

    _rotation_view = new Vec4SlidersView({ 0, 0, 168, _height });
    add_subview(_rotation_view);

}
