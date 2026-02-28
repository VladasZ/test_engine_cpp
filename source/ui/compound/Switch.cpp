//
//  Switch.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 17/12/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Touch.hpp"
#include "Switch.hpp"

using namespace ui;


bool Switch::is_selected() const {
    return _is_selected;
}

void Switch::set_value(bool value) {
    _is_selected = value;
    on_value_changed(value);
    _set_needs_layout();
}

void Switch::set_caption(const std::string& caption) {
    _label->set_text(caption);
}

void Switch::setup() {
    init_view(_switch);
    _switch->init_view(_label);
    _switch->background_color = Color::blue;
    enable_touch();
    on_touch = [&](Touch* touch) {
        if (!touch->is_began()) return;
        set_value(!_is_selected);
    };
}

void Switch::layout() {

    static constexpr float indent = 4.0f;

    auto half_width = _frame.size.width / 2;

    _switch->edit_frame() = {indent,
                             indent,
                             half_width - indent,
                             _frame.size.height - indent * 2
    };

    if (_is_selected) {
        _switch->edit_frame().origin.x += half_width - indent;
    }

    background_color = _is_selected ? Color::green : Color::clear;

    _label->edit_frame() = _switch->frame().with_zero_origin();

}
