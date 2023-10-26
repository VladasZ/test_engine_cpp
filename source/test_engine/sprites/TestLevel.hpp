//
//  TestLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once


#include "SpritesInclude.hpp"

#ifdef USING_SPRITES

#include "Body.hpp"
#include "Unit.hpp"
#include "Level.hpp"
#include "ControlPad.hpp"
#include "DynamicBody.hpp"


namespace te {

	class TestLevel : public sprite::Level {

	    sprite::Body* floor = nullptr;
        sprite::Body* right = nullptr;
        sprite::Body* left = nullptr;
		sprite::DynamicBody* box = nullptr;

		sprite::Unit* unit = nullptr;

	public:

		TestLevel();

		void setup() override;

	};

}

#endif
