//
//  ScrollTestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "ScrollTestView.hpp"
#include "RangeConversion.hpp"

using namespace cu;
using namespace ui;
using namespace te;


RangeConversion conv;

void ScrollTestView::_setup() {

    init_view(test_view, { 200, 300 });
    init_view(file_manager, { 300, 400 });

}

void ScrollTestView::_layout() {
    _calculate_absolute_frame();
    test_view->edit_frame().origin = { };
    file_manager->place_bl();
    _layout_subviews();
}
