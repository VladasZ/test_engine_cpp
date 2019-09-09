//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "TestView.hpp"

using namespace ui;

void TestView::_setup() {

    stick = new AnalogStickView();
    stick->on_direction_change.subscribe([](auto point){
        TestView::on_stick_move(point);
    });
    add_subview(stick);

    button = new Button();
    add_subview(button);

    button->on_press.subscribe([]{
        Log("SOPOK");
    });
}

void TestView::_layout() {

    _frame = _superview->frame();

    View::_layout();

    stick->set_center(_frame.size.center());

    button->set_frame({
                              0,
                              _frame.size.height - 100,
                              100,
                              100
                      });

    stick->set_center({
                              _frame.size.width - stick->frame().size.width / 2 - 40,
                              _frame.size.height - stick->frame().size.height / 2 - 40,
                      });
}
