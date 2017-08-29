//
//  Size.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Types.h"

class Size {
    
public:
    
    Float width = 0, height = 0;
    
    Size() = default;
    Size(Float width, Float height);
};
