//
//  Gamepad.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 23/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "Point.hpp"


namespace ui {

	class Gamepad {

	public:

		static inline bool a;
		static inline bool b;
		static inline bool x;
		static inline bool y;

		static inline bool lb;
		static inline bool rb;

		static inline bool back;
		static inline bool start;

		static inline float lt;
		static inline float rt;

		static inline bool up    = false;
		static inline bool right = false;
		static inline bool down  = false;
		static inline bool left  = false;

		static inline gm::Point left_stick;
		static inline gm::Point right_stick;

	};

}
