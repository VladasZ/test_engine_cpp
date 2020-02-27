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

    init_view(testView, { 200, 300 });

    testView->clips = true;

}

void ScrollTestView::_layout() {
    _calculate_absolute_frame();
    testView->place_at_center();
    _layout_subviews();
}
