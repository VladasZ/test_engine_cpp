//
//  Random.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/28/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "Singletone.hpp"

class Random : Static {
public:
	static Color color();
};
