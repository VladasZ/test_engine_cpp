//
//  ControlPad.hpp
//  ui
//
//  Created by Vladas Zakrevskis on 20/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "ImageButton.hpp"


namespace ui {

	class ControlPad : public View {

	public:

		using View::View;

		void set_images(Image* up, Image* down, Image* left, Image* right);

	protected:

		void setup() override;
		void layout() override;

	private:

		ImageButton* up    = nullptr;
		ImageButton* down  = nullptr;
		ImageButton* left  = nullptr;
		ImageButton* right = nullptr;

	public:

		cu::Event<> on_up;
		cu::Event<> on_down;
		cu::Event<> on_left;
		cu::Event<> on_right;

		cu::Event<gm::Direction> on_press;

	};
}
