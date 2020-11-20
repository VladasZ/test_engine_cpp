//
//  Paths.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/14/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#pragma once

#include "Path.hpp"

namespace te {
    
    struct Paths {

        static const cu::Path root;
        static const cu::Path assets;
        static const cu::Path images;
        static const cu::Path models;
        static const cu::Path fonts;

        static const cu::Path downloads;

        struct Shaders {
			static const cu::Path root;
            static const cu::Path ui;
            static const cu::Path sprites;
            static const cu::Path isometric;
            static const cu::Path include;
            static const cu::Path test;
		};

		static void dump();

    };
    
};

