//
//  TestLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "DynamicBody.hpp"


class TestLevel : public sprite::Level {

    sprite::Platform* floor;
	sprite::DynamicBody* box;
	sprite::DynamicBody* box2;

public:

	TestLevel();

    void update() override;

};
