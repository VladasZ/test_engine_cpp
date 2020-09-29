//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 4/29/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "System.hpp"
#include "Assets.hpp"
#include "Screen.hpp"
#include "Dispatch.hpp"
#include "RootView.hpp"
#include "SelectionView.hpp"

using namespace cu;
using namespace ui;
using namespace scene;


SelectionView::~SelectionView() {
    te::Screen::current->scene()->on_model_selected.unsubscribe(this);
    te::Screen::current->scene()->on_model_moved.unsubscribe(this);
}

void SelectionView::setup() {

    add_subview(object_info_view = new ObjectInfoView());
    object_info_view->edit_frame() = { 400, 80 };
    object_info_view->enable_resize();

    init_view(button, { 100, 100 });
    button->set_caption("Button");

    add_subview(revolving_view = View::dummy());

    image = new ImageView({ 60, 80 }, Assets::images->cat);
    add_subview(image);

    switcher = new Switch();
    switcher->edit_frame() = { 100, 50 };
    add_subview(switcher);

    switcher->on_value_changed = [](bool value) {
        te::RootView::set_draw_touches(value);
    };

    button->on_press = [&] {
        cu::System::alert("Hellou");
        button->background_color = Color::random();
    };

    auto set_model = [&](Model* model) {
        object_info_view->set_object(model);
    };

    te::Screen::current->scene()->on_model_selected.subscribe(this) = set_model;
    te::Screen::current->scene()->on_model_moved.subscribe(this) = set_model;

}

void SelectionView::layout() {

    button->place_bl();

    switcher->place_tr(10);

    static float angle = 0;
    revolving_view->set_center(Point::on_circle(100, angle, { 200, 200 }));
    angle += 0.01f;

    image->place_at_bottom(100);

    object_info_view->stick_to(button, gm::Edge::Right, 10);

}
