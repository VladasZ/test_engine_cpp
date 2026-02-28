//
//  StackView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 12/29/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "StackView.hpp"

using namespace ui;


void StackView::set_margin(float margin) {
    _margin = margin;
}

void StackView::layout() {

    if (_subviews.empty()) return;

    if (_subviews.size() == 1) {
        _subviews.front()->edit_frame() = _frame.with_zero_origin();
        return;
    }

    const auto height = (_frame.size.height - _margin * (_subviews.size() - 1)) / _subviews.size();

    _subviews.front()->edit_frame() =
            { 0,
              0,
              _frame.size.width,
              height
            };

    for (size_t i = 1; i < _subviews.size(); i++) {
        _subviews[i]->edit_frame() = _subviews.front()->frame();
        _subviews[i]->edit_frame().origin.y = (height + _margin) * i;
    }

}
