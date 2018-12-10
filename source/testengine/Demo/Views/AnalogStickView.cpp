//
//  AnalogStickView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/12/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "Input.hpp"
#include "Event.hpp"
#include "AnalogStickView.hpp"

using namespace std;

static const float SIZE = 140;
static const float OUTLINE_WIDTH = 10;
static const float STICK_VIEW_SIZE = SIZE / 2;

AnalogStickView::AnalogStickView() : DrawingView({ SIZE, SIZE }) { }

void AnalogStickView::setup() {
    auto outer_path = Path::circle_with(_frame.size.center(), _frame.size.width);
    outer_path->_color = ui::Color::black;
    add_path(outer_path);

    auto outline_path = Path::circle_with(_frame.size.center(), _frame.size.width - OUTLINE_WIDTH);
    outline_path->_color = ui::Color::white;
    add_path(outline_path);

    direction_stick = new DrawingView({ STICK_VIEW_SIZE, STICK_VIEW_SIZE });
    direction_stick->set_center(_frame.size.center());
    add_subview(direction_stick);

    direction_stick->add_path([&]() {
        auto path = Path::circle_with(direction_stick->frame().size.center(),
                                     STICK_VIEW_SIZE);
        path->_color = ui::Color::black;
        return path;
    }());
    
    direction_stick->add_path([&]() {
        auto path = Path::circle_with(direction_stick->frame().size.center(),
                                     STICK_VIEW_SIZE - OUTLINE_WIDTH);
        path->_color = ui::Color::light_gray;
        return path;
    }());
    
}

void AnalogStickView::on_touch_moved(const ui::Point &touch) {
    
    float max_lenght = _frame.size.height / 2;
    
	ui::Point touch_position = local_point_from(touch);
	ui::Point vector = touch_position - _frame.size.center();
    
    if (vector.length() > max_lenght) {
        vector = vector.with_length(max_lenght);
        touch_position = _frame.size.center() + vector;
    }
    
    direction_stick->set_center(touch_position);
	on_direction_change(vector * 0.1f);
}
