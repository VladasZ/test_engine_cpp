//
//  GamepadView.cpp
//  ui
//
//  Created by Vladas Zakrevskis on 26/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#include "GamepadView.hpp"

using namespace ui;

static void layout_pad(View* container, View* t, View* b, View* l, View* r) {
	auto third = container->frame().size.width / 3;
	t->edit_frame() = { third, 0, third, third };
	b->edit_frame() = { third * 2, third, third, third };
	r->edit_frame() = { 0, third, third, third };
	l ->edit_frame() = { third, third * 2, third, third };
}


void GamepadView::setup() {

	init_view(buttons, { 100, 100 });

	buttons->init_view(a)->set_text("A");
	buttons->init_view(b)->set_text("B");
	buttons->init_view(x)->set_text("X");
	buttons->init_view(y)->set_text("Y");

	buttons->on_layout = [this] { layout_pad(buttons, y, a, x, b); };

	init_view(dpad, { 100, 100 });

	dpad->init_view(up);
	dpad->init_view(right);
	dpad->init_view(down);
	dpad->init_view(left);

	dpad->on_layout = [this] { layout_pad(dpad, up, down, left, right); };

	init_view(left_stick);
	init_view(right_stick);

}

void GamepadView::layout() {

	dpad->place.bl();
	buttons->place.br();

	left_stick->place.to(dpad, Edge::Top);
	right_stick->place.to(buttons, Edge::Top);

}
