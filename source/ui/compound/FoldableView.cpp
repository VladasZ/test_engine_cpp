//
//  FoldableView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 27/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "FoldableView.hpp"

using namespace ui;


FoldableView::FoldableView(View* main, View* folded) {
    add_subview(_main_view = main);
    add_subview(_hidden_view = folded);
}

void FoldableView::set_folded(bool folded) {
    _folded = folded;
    _hidden_view->is_hidden = folded;
    if (folded) {
        _frame.size = { _main_view->frame().max_x(), _main_view->frame().max_y() };
    }
    else {
        _frame.size.height = _hidden_view->frame().max_y();
        _frame.size.width = _hidden_view->frame().max_x();
    }
    on_folded(folded);
}

void FoldableView::setup() {
    init_view(_unfold_button);
    _unfold_button->on_press = [&] {
        set_folded(!_folded);
    };
}

void FoldableView::layout() {
    _hidden_view->edit_frame().origin.y = _main_view->frame().max_y();
    set_folded(_folded);
    _unfold_button->edit_frame() = _frame.with_zero_origin();
    _unfold_button->edit_frame().size.height = _main_view->frame().size.height;
}
