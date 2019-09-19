//
//  TestLevel.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 7/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Box2D/Box2D.h"

#include "Level.hpp"
#include "Platform.hpp"
#include "DynamicBody.hpp"

class TestLevel : public sprites::Level {

    b2Body* box_body;

    sprites::Platform* floor;
    sprites::DynamicBody* box;

public:

	TestLevel();

    void update() override;


};

