//
//  Button.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 28/01/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Touch.hpp"
#include "Button.hpp"

using namespace ui;


Button::Button(const Rect& frame) : View(frame) {
    enable_touch();
    init_view(_caption_label);
    on_touch = [&](Touch* touch) {
        if (touch->is_began()) {
            on_press();
        }
    };
}

Button* Button::set_caption(const std::string& caption) {
    _caption_label->set_text(caption);
    return this;
}

Button* Button::set_alignment(Edge alignment) {
    _caption_label->set_alignment(alignment);
    return this;
}

void Button::layout() {
    _caption_label->edit_frame() = _frame.with_zero_origin();
}
