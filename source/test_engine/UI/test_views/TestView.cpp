//
//  TestView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/02/2020.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "GLWrapper.hpp"
#include "GamepadView.hpp"
#include "assets/Assets.hpp"

using namespace ui;

void te::TestView::setup() {

  ScrollView::setup();

  init_view(view, {100, 100});
  init_view(label, {100, 100});
  init_view(button, {100, 100});
  init_view(image_view, {100, 100});

  view->background_color = gm::Color::random();
  label->set_text("Text");
  button->on_press = [&] { button->background_color = gm::Color::random(); };
  image_view->set_image(Assets::images->cat);

  fold_caption_label = new Label({100, 50});
  fold_caption_label->set_text("Fold");

  folded_stack_view = new StackView({50, 0, 200, 5000});

  for (int i = 0; i < 100; i++) {
    auto lobel = new Label({300, 50});
    lobel->set_text(std::to_string(i) + " lobel");
    folded_stack_view->add_subview(lobel);
  }

  add_subview(foldableView =
                  new FoldableView(fold_caption_label, folded_stack_view));

  foldableView->on_folded = [&](bool folded) {
    content_size.height = foldableView->frame().max_y();
    if (folded) {
      content_offset = {};
    }
  };

  init_view(gamepad_view, {400, 400});

  GL::on_gamepad_update = [this](const GL::GamepadData &gamepad) {
    gamepad_view->left_stick->set_direction(gamepad.left_stick);
    gamepad_view->right_stick->set_direction(gamepad.right_stick);

    static constexpr auto color_from_bool = [](bool val) {
      return val ? gm::Color::blue : gm::Color::clear;
    };

    gamepad_view->a->background_color = color_from_bool(gamepad.a);
    gamepad_view->b->background_color = color_from_bool(gamepad.b);
    gamepad_view->x->background_color = color_from_bool(gamepad.x);
    gamepad_view->y->background_color = color_from_bool(gamepad.y);

    gamepad_view->up->background_color = color_from_bool(gamepad.up);
    gamepad_view->down->background_color = color_from_bool(gamepad.down);
    gamepad_view->left->background_color = color_from_bool(gamepad.left);
    gamepad_view->right->background_color = color_from_bool(gamepad.right);
  };
}

void te::TestView::layout() {

  ScrollView::layout();

  view->place.tr(30);
  label->place.at_center();
  button->place.br(30);
  image_view->place.bl();
  foldableView->edit_frame().origin = {};

  gamepad_view->place.at_bottom();
  gamepad_view->place.center_hor();
}
