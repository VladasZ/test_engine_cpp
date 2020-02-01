//
//  TestLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#ifdef USING_BOX2D

#include "Box2D/Box2D.h"

#include "Level.hpp"
#include "Platform.hpp"
#include "DynamicBody.hpp"

class TestLevel : public sprites::Level {

    sprites::Platform* floor;
	sprites::DynamicBody* box;
	sprites::DynamicBody* box2;

public:

	TestLevel();

    void update() override;

};

#endif
