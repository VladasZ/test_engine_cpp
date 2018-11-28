//
//  Random.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/28/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Random.hpp"
#include "Array.hpp"

Color Random::color() {

	static const Array<Color> colors = {
		Color::black,
		Color::white,
		Color::red,
		Color::green,
		Color::blue,
		Color::light_blue,
		Color::yellow,
		Color::orange,
		Color::purple,
		Color::turquoise,
		Color::light_gray
	};

	return colors.random();
}
