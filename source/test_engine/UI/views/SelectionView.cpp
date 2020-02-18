//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Time.hpp"
#include "System.hpp"
#include "Assets.hpp"
#include "Dispatch.hpp"
#include "RootView.hpp"
#include "SelectionView.hpp"

using namespace cu;
using namespace ui;
using namespace gm;


void SelectionView::_setup() {

    add_subview(object_info_view = new ObjectInfoView());

    object_info_view->edit_frame() =
            { 300,
              300,
              300,
              300
            };

    object_info_view->enable_resize();

    button = new Button();
    button->set_caption("Button");
    add_subview(button);

    add_subview(revolving_view = View::dummy());

    image = new ImageView({ 60, 80 }, Assets::images->cat);
    add_subview(image);

    sliders = new Vec4SlidersView();
    sliders->edit_frame() = { 0, 100, 200, 300 };
    add_subview(sliders);

    switcher = new Switch();
    add_subview(switcher);

    switcher->on_value_changed = [](bool value) {
        te::RootView::set_draw_touches(value);
    };

    button->on_press = [&] {
        cu::System::alert("Hellou");
        button->background_color = Color::random();
    };

    enable_touch();

    on_touch = [](Touch* touch) {

        static Axis selected_axis = Axis::None;

        if (touch->is_ended()) {
            selected_axis = Axis::None;
            return;
        }

        if (touch->is_moved() && selected_axis != Axis::None) {

            auto ray = SelectionScene::instance->camera->cast_ray(touch->location);
            auto selected_model = SelectionScene::instance->selected_model;

            auto& position = selected_model->position();

            auto axis_vector = selected_model->position();
            axis_vector.set_axis(selected_axis, position.get_axis(selected_axis) + 1.0f);

            Ray axis_ray { position, axis_vector };

            Log(axis_ray);

          //  axis_ray.set_axis()

            auto point = ray.spes(axis_ray).second;

            selected_model->edit_position() = point;
            SelectionScene::instance->position_manipulator->edit_position() = point;

            object_info_view->set_object(selected_model);

            Logvar(point);

        }

        if (touch->is_began()
#ifdef DESKTOP_BUILD
            && touch->is_left_click()
#endif
        ) {
            if (SelectionScene::instance) {

                auto ray = SelectionScene::instance->camera->cast_ray(touch->location);

                auto axis = SelectionScene::instance->select_axis(ray);

                if (axis != Axis::None) {
                    selected_axis = axis;
                    return;;
                }

                auto model = SelectionScene::instance->select_model(ray);

                if (model != nullptr) {
                    object_info_view->set_object(model);
                }
                else {
                    object_info_view->clear();
                }
            }
        }
    };

}

void SelectionView::_layout() {

    _frame = _superview->frame().with_zero_origin();

    button->edit_frame() =
            { 0,
              _frame.size.height - 100,
              100,
              100
            };

    static float angle = 0;
    revolving_view->set_center(Point::on_circle(200, angle, { 300, 300 }));
    angle += 0.01;

    auto switcher_size = 100.0f;

    switcher->edit_frame() =
            { _frame.size.width - switcher_size - 20,
              20,
              switcher_size,
              switcher_size / 2
            };

    image->set_center({ _frame.size.width / 2, _frame.size.height - 100 });

    View::_layout();
}
