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


void WorldView::setup() {
    init_view(test_label, { 500, 100 });
    init_view(test_view, { 200, 200 });
    init_view(file_manager, { 300, 400 });

    std::string spes;

    for (char i = 0; i < 127; i++) {
        spes += i;
    }

    test_label->set_text(spes);

}

void WorldView::layout_subviews() {
    file_manager->place_bl();
    test_view->place_at_center();
}
