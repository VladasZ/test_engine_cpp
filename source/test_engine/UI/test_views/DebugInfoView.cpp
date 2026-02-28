//
//  DebugInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/9/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "DebugInfoView.hpp"
#include "GlobalEvents.hpp"
#include "Input.hpp"
#include "Screen.hpp"
#include "ui/ui.hpp"

using namespace ui;

void DebugInfoView::setup() {

  init_view(_stack_view);

  _stack_view->set_margin(5);

  _stack_view->init_view(_fps_label);
  _stack_view->init_view(_frames_drawn_label);
  _stack_view->init_view(_cursor_position_label);
  _stack_view->init_view(_touch_state_label);
  _stack_view->init_view(info_label);

  Events::frame_drawn = [&] {
    static int frames_drawn = 0;
    _frames_drawn_label->set_text(
        std::string() + "Frames drawn: " + std::to_string(++frames_drawn));
    _fps_label->set_text(std::string() +
                         "FPS: " + std::to_string(te::Screen::FPS));
  };

#ifdef MOUSE
  ui::Mouse::on_moved = [&](Point position) {
    _cursor_position_label->set_text(
        std::string() + "Cursor: " + ui::Mouse::frame_shift.to_string());
  };
#endif

  ui::Input::on_touch = [&](ui::Touch *touch) {
    _touch_state_label->set_text(std::string() +
                                 "Touch state: " + touch->event_string());
  };

  _superview = this;
}

void DebugInfoView::layout() { _stack_view->edit_frame().size = _frame.size; }
