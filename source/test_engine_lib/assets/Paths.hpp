//
//  Paths.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include <boost/filesystem.hpp>

namespace te {
    
    using Path = boost::filesystem::path;
    using PathsArray = std::vector<Path>;
    
    namespace Paths {
        Path root();
        Path assets();
        Path images();
        Path models();
        Path fonts();

		namespace Shaders {
			Path root();
			Path ui();
			Path sprites();
			Path isometric();
		}
        
        PathsArray ls(Path = ".");
    };
    
};

