//
//  DebugInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/9/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Screen.hpp"
#include "GlobalEvents.hpp"
#include "DebugInfoView.hpp"

#ifdef DEBUG_VIEW

void DebugInfoView::_setup() {

    _stack_view = new ui::StackView();

    _fps_label = new ui::Label();
    _frames_drawn_label = new ui::Label();
    _cursor_position_label = new ui::Label();
    _touch_state_label = new ui::Label();
    info_label = new ui::Label();

    for (auto label : { _fps_label, _frames_drawn_label, _cursor_position_label, _touch_state_label, info_label }) {
        label->resize_to_fit_text();
        _stack_view->add_subview(label);
    };

    _stack_view->set_margin(5);
    _stack_view->set_alignment(ui::Alignment::Left);

    add_subview(_stack_view);

    Events::frame_drawn.subscribe([&]{
        static int frames_drawn = 0;
        _frames_drawn_label->set_text(std::string() + "Frames drawn: " + std::to_string(++frames_drawn));
        _fps_label->set_text(std::string() + "FPS: " + std::to_string(Screen::FPS));
    });

    Events::cursor_moved.subscribe([&](Point position){
        _cursor_position_label->set_text(std::string() + "Cursor: " + position.to_string());
    });

    Events::touch.subscribe([&](ui::Touch* touch){
        _touch_state_label->set_text(std::string() + "Touch state: " + touch->event_string());
    });
}

void DebugInfoView::_draw() {
    ui::View::_draw();
}

void DebugInfoView::_layout() {
    _calculate_absolute_frame();

    _stack_view->edit_frame([&](Rect& frame){
       frame.size = this->_frame.size;
    });

    _layout_subviews();
}

#endif
