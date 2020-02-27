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

        static cu::Path root;
        static cu::Path assets;
        static cu::Path images;
        static cu::Path models;
        static cu::Path fonts;

        static cu::Path downloads;

        struct Shaders {
			static cu::Path root;
            static cu::Path ui;
            static cu::Path sprites;
            static cu::Path isometric;
            static cu::Path include;
            static cu::Path test;
		};

		static void dump();

    };
    
};

