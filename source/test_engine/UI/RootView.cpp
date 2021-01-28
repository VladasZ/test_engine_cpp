//
//  RootView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/8/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ui.hpp"
#include "Input.hpp"
#include "Touch.hpp"
#include "RootView.hpp"

using namespace te;
using namespace ui;


void RootView::setup() {
    background_color = gm::Color::clear;

    _draw_touches = false;

    Input::on_touch = [this](Touch* touch) {
        if (!_draw_touches) return;
        auto view = View::dummy({ 5, 5 });
        view->place.set_center(touch->position);
        add_subview(view);
        _touch_views.push_back(view);
    };

    _superview = this;
}

void RootView::set_draw_touches(bool value) {
    _draw_touches = value;
    if (!value) {
        for (auto view : _touch_views) {
            view->remove_from_superview();
        }
        _touch_views.clear();
    }
}
