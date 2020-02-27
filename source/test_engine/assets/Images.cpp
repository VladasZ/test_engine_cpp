//
//  Images.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/4/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "Images.hpp"

using namespace te;


Images::Images() {
    cat        = new Image(Paths::images / "cat.jpg");
    palm       = new Image(Paths::images / "palm.png");
    round      = new Image(Paths::images / "round.png");
    square     = new Image(Paths::images / "square.png");
    scale_test = new Image(Paths::images / "scale_test.png");
}
