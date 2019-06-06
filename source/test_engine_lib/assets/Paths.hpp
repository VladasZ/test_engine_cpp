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
    
    namespace Paths {
        Path root();
        Path assets();
        Path shaders();
        Path images();
        Path models();
        Path fonts();
    };
    
};

