//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Assets.hpp"
#include "TestView.hpp"
#include "GamepadView.hpp"

using namespace ui;


void te::TestView::setup() {

    ScrollView::setup();

    init_view(view,       { 100, 100 });
    init_view(label,      { 100, 100 });
    init_view(button,     { 100, 100 });
    init_view(image_view, { 100, 100 });

    view->background_color = gm::Color::random();
    label->set_text("Text");
    button->on_press = [&] { button->background_color = gm::Color::random(); };
    image_view->set_image(Assets::images->cat);


    fold_caption_label = new Label({ 100, 50 });
    fold_caption_label->set_text("Fold");

    folded_stack_view = new StackView({ 50, 0, 200, 5000 });

    for (int i = 0; i < 100; i++) {
        auto lobel = new Label({ 300, 50 });
        lobel->set_text(std::to_string(i) + " lobel");
        folded_stack_view->add_subview(lobel);
    }

    add_subview(foldableView = new FoldableView(fold_caption_label, folded_stack_view));

    foldableView->on_folded = [&] (bool folded) {
        content_size.height = foldableView->frame().max_y();
        if (folded) {
            content_offset = { };
        }
    };

    init_view(gamepad, { 400, 400 });

}

void te::TestView::layout() {

    ScrollView::layout();

    view->place.tr(30);
    label->place.at_center();
    button->place.br(30);
    image_view->place.bl();
    foldableView->edit_frame().origin = { };

    gamepad->place.at_bottom();
    gamepad->place.center_hor();

}
