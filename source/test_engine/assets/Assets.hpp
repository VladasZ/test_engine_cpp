//
//  Assets.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/3/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Images.hpp"
#include "Buffers.hpp"
#include "Shaders.hpp"


struct Assets {
    static inline Images* images;
    static inline Buffers* buffers;
    static inline Shaders* shaders;

    static void initialize();
};
