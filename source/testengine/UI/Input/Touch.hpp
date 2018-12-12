//
//  Touch.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/21/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include <stdint.h>

#include "Point.hpp"

class Touch {
public:

	enum Event : uint8_t {
		Began = 0b0000'0001,
		Moved = 0b0000'0010,
		Ended = 0b0000'0100,
		All = Began | Moved | Ended
	};

	ui::Point location;
    Event event;

	Touch(const ui::Point& location, Event event);

	bool is_began() const;
	bool is_moved() const;
	bool is_ended() const;
};
