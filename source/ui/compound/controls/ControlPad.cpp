//
//  ControlPad.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 20/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "ControlPad.hpp"

using namespace ui;
using namespace gm;


void ControlPad::set_images(Image* u, Image* d, Image* l, Image* r) {
	up   ->set_image(u);
	down ->set_image(d);  
	left ->set_image(l);
	right->set_image(r);
}

void ControlPad::setup() {
	init_view(up   );
	init_view(down );
	init_view(left );
	init_view(right);

	up   ->on_press = [&] { on_up   (); on_press(Direction::Up   ); };
	down ->on_press = [&] { on_down (); on_press(Direction::Down ); };
	left ->on_press = [&] { on_left (); on_press(Direction::Left ); };
	right->on_press = [&] { on_right(); on_press(Direction::Right); };
}

void ControlPad::layout() {
	auto width  = _frame.size.width  / 3;
	auto height = _frame.size.height / 2;

	up->edit_frame() = {
		_frame.size.width / 2 - width / 2,
		0,
		width,
		height
	};

	left->edit_frame() = {
		0,
		height,
		width,
		height
	};

	down->edit_frame() = {
		width,
		height,
		width,
		height
	};

	right->edit_frame() = {
		width * 2,
		height,
		width,
		height
	};
}
