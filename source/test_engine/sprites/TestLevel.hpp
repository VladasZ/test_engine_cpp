//
//  TestLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Level.hpp"
#include "Platform.hpp"
#include "DynamicBody.hpp"


namespace te {

	class TestLevel : public sprite::Level {

		sprite::DynamicBody* box;

	public:

		TestLevel();

		void update() override;

	};

}
