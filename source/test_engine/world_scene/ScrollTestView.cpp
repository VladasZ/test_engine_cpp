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


    fold_caption_label = new Label({ 300, 50 });
    fold_caption_label->set_text("Fold");

    folded_stack_view = new StackView({ 50, 0, 300, 250 });

    for (int i = 0; i < 5; i++) {
        auto lobel = new Label({ 300, 50 });
        lobel->set_text(std::to_string(i) + " lobel");
        folded_stack_view->add_subview(lobel);
    }

  //  fold_caption_label->edit_frame().origin.x = 500;

    init_view(foldableView);
    init_view(testView, { 300, 300 });

    foldableView->add_subview(foldableView->main_view = fold_caption_label);
    foldableView->add_subview(foldableView->hidden_view = folded_stack_view);

  //  foldableView->set_folded(true);

    testView->clips = true;
    testView->content_size = { 300, 600 };

}

void ScrollTestView::_layout() {
    _calculate_absolute_frame();
    testView->place_at_center();
    _layout_subviews();
}
