//
//  Touch.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/21/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"

class Touch {
public:

	enum Event : uint8_t {
		Began = 0b0000'0001,
		Moved = 0b0000'0010,
		Ended = 0b0000'0100,
		All = Began | Moved | Ended
	};

	Event event;
	Point location;

	Touch(const Point& location, Event event);

	bool isBegan() const { return event == Event::Began; }
	bool isMoved() const { return event == Event::Moved; }
	bool isEnded() const { return event == Event::Ended; }
};
