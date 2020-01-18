//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Time.hpp"
#include "Assets.hpp"
#include "Dispatch.hpp"
#include "TestView.hpp"
#include "RootView.hpp"

using namespace cu;
using namespace ui;
using namespace gm;

void TestView::_setup() {

    button = new Button();
    add_subview(button);

    add_subview(revolving_view = View::dummy());


#ifndef DESKTOP_BUILD
    add_subview(left_stick = new AnalogStickView());
    left_stick->on_direction_change.subscribe([](auto point) {
        TestView::on_left_stick_move(point);
    });
    
    add_subview(right_stick = new AnalogStickView());
    right_stick->on_direction_change.subscribe([](auto point) {
        TestView::on_right_stick_move(point);
    });
#endif

//    image = new ImageView({ 60, 80 }, Assets::images->cat);
//    add_subview(image);

//    sliders = new Vec4SlidersView();
//    add_subview(sliders);

    switcher = new Switch();
    add_subview(switcher);

    switcher->on_value_changed.subscribe([](bool value) {
        te::RootView::set_draw_touches(value);
    });
    
    button->on_press.subscribe([&] {
        button->background_color = Color::random();
    });

}

void TestView::_layout() {
    
    _frame = _superview->frame().with_zero_origin();
        
    button->set_frame({
        0,
        _frame.size.height - 100,
        100,
        100
    });
    
    static const float margin = 40;
    

#ifndef DESKTOP_BUILD
    left_stick->set_center({
        left_stick->frame().size.width / 2 + margin,
        _frame.size.height - left_stick->frame().size.height / 2 - margin,
    });
    
    right_stick->set_center({
        _frame.size.width - right_stick->frame().size.width / 2 - margin,
        _frame.size.height - right_stick->frame().size.height / 2 - margin,
    });
#endif

    sliders->set_frame({ 0, 100, 200, 300 });

    static float angle = 0;
    revolving_view->set_center(Point::on_circle(200, angle, { 300, 300 }));
    angle += 0.01;

    auto switcher_size = 100.0f;

    switcher->set_frame({
        _frame.size.width - switcher_size - 20,
        20,
        switcher_size,
        switcher_size / 2
    });

    image->set_center({ _frame.size.width / 2, _frame.size.height - 100 });

    View::_layout();
}
