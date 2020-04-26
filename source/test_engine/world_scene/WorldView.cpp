//
//  WorldView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "WorldView.hpp"

using namespace ui;
using namespace te;


void WorldView::_setup() {
    init_view(file_manager, { 300, 400 });
}

void WorldView::_layout() {
    _calculate_absolute_frame();
    file_manager->place_bl();
    _layout_subviews();
}
