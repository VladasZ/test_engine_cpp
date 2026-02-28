//
//  GamepadView.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 26/01/21.
//  Copyright © 2021 VladasZ. All rights reserved.
//

#pragma once

#include "Label.hpp"
#include "Slider.hpp"
#include "AnalogStickView.hpp"


namespace ui {

	class GamepadView : public View {

	public:

		using View::View;

	public:

		Label* a;
		Label* b;
		Label* x;
		Label* y;

		View* buttons;

		View* lb;
		View* rb;

		View* back;
		View* start;

		Slider* lt;
		Slider* rt;

		View* up;
		View* right;
		View* down;
		View* left;

		View* dpad;
		

		AnalogStickView* left_stick;
		AnalogStickView* right_stick;

	protected:

		void setup() override;
		void layout() override;

	};

}
