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
    init_view(test_view, { 200, 300 });
    Rect rect(100, 400, 100, 100);
    square = new View(rect);
    add_subview(square);
    square->background_color = Color::random();
    rect.origin.y = 100;
    change_color_button = new Button(rect);
    add_subview(change_color_button);
    change_color_button->on_press = [this]{
        std::cout << "Hello" << std::endl;
        square->background_color = Color::random();
    };
}

void WorldView::layout_subviews() {
    test_view->place_br();
}
