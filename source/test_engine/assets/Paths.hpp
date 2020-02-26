//
//  Paths.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "system/Path.hpp"

namespace te {
    
    namespace Paths {
        cu::Path root();
        cu::Path assets();
        cu::Path images();
        cu::Path models();
        cu::Path fonts();

        cu::Path downloads();

		namespace Shaders {
			cu::Path root();
			cu::Path ui();
			cu::Path sprites();
			cu::Path isometric();
            cu::Path include();
            cu::Path test();
		}

		void dump();

    };
    
};

