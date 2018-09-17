//
//  Box.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Box.hpp"


Box::Box() {
    vertices = {
    
		{ -1.0, -1.0,  1.0 },
		{ 1.0, -1.0,  1.0  },
		{ -1.0,  1.0,  1.0 },
		{ 1.0,  1.0,  1.0  },
		{ -1.0, -1.0, -1.0 },
		{ 1.0, -1.0, -1.0  },
		{ -1.0,  1.0, -1.0 },
		{ 1.0,  1.0, -1.0  }
    };

	indices = {
		0, 1, 2, 3, 7, 1, 5, 4, 7, 6, 2, 4, 0, 1
	};
}
