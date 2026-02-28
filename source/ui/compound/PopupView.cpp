//
//  PopupView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 19/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include <Input.hpp>
#include "PopupView.hpp"

using namespace ui;


PopupView::~PopupView() {
#ifdef MOUSE
    Input::on_hover_moved.unsubscribe(this);
#endif
}

void PopupView::set_caption(const std::string& caption) {
    _main_button->set_caption(caption);
}

void ui::PopupView::add_action(const std::string& caption, std::function<void()> action) {
    auto button = new Button();
    button->set_caption(caption);
    button->on_press = action;
    _stack_view->add_subview(button);
    _buttons.push_back(button);
}

void ui::PopupView::setup() {

    add_subview(_main_button);
    init_view(_stack_view);
    _stack_view->is_hidden = true;


#ifdef MOUSE

    Input::on_hover_moved.subscribe(this) = [&](const Point& location) {

        if (!_stack_view->is_hidden) {
            bool visible = absolute_frame().contains(location) || _stack_view->contains_global_point(location);
            _stack_view->is_hidden = !visible;
            return;
        }

        _stack_view->is_hidden = !absolute_frame().contains(location);
    };

#else

    _main_button->on_press = [&] {
        _stack_view->is_hidden = !_stack_view->is_hidden;
    };

#endif

}

void ui::PopupView::layout() {

    _main_button->edit_frame() = _frame.with_zero_origin();

    auto stack_height = _frame.size.height * _buttons.size();

    _stack_view->edit_frame() =
            { 0,
              -stack_height,
              _frame.size.width,
              stack_height
            };

}
