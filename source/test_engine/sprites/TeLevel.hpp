//
//  TeLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 26/11/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Level.hpp"
#include "ControlPad.hpp"
#include "SpritesInclude.hpp"
#include "AnalogStickView.hpp"


namespace te {

	class TeLevel : public sprite::Level {

	protected:

		sprite::Sprite* selected_sprite = nullptr;
		ui::ControlPad* control_pad = nullptr;
		ui::AnalogStickView* stick = nullptr;

	public:

		cu::Event<ui::Touch*> on_touch;

		TeLevel();
		TeLevel(ui::ControlPad*, ui::AnalogStickView*);

	protected:

		void setup() override;

	private:

		void setup_controls();

	protected:

		gm::Point convert_touch(const gm::Point&) override;

#ifdef DESKTOP_BUILD
		gm::Point mouse_position() override;
#endif

	};

}
