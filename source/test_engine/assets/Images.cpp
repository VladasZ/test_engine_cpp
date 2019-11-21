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
    cat    = new Image(Paths::images() / "cat.jpg");
    palm   = new Image(Paths::images() / "palm.png");
    square = new Image(Paths::images() / "square.png");
}
