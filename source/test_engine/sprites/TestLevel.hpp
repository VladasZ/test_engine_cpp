//
//  TestLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Unit.hpp"
#include "Level.hpp"
#include "Platform.hpp"
#include "ControlPad.hpp"
#include "DynamicBody.hpp"


namespace te {

	class TestLevel : public sprite::Level {

	    sprite::Platform* floor = nullptr;
        sprite::Platform* right = nullptr;
        sprite::Platform* left = nullptr;
		sprite::DynamicBody* box = nullptr;

		sprite::Unit* unit = nullptr;

	public:

		ui::ControlPad* control_pad = nullptr;

		TestLevel();

		void update() override;
		void setup() override;

	};

}
