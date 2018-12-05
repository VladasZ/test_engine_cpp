//
//  Random.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/28/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Random.hpp"
#include "Array.hpp"

ui::Color Random::color() {

	static const Array<ui::Color> colors = {
		ui::Color::black,
		ui::Color::white,
		ui::Color::red,
		ui::Color::green,
		ui::Color::blue,
		ui::Color::light_blue,
		ui::Color::yellow,
		ui::Color::orange,
		ui::Color::purple,
		ui::Color::turquoise,
		ui::Color::light_gray
	};

	return colors.random();
}
