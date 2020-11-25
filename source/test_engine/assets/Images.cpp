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

    file   = new Image(Paths::images / "file.png");
    text   = new Image(Paths::images / "text.png");
    cmake  = new Image(Paths::images / "cmake.png");
    image  = new Image(Paths::images / "image.png");
    folder = new Image(Paths::images / "folder.png");


    up    = new Image(Paths::images / "up.png");
    down  = new Image(Paths::images / "down.png");
    left  = new Image(Paths::images / "left.png");
    right = new Image(Paths::images / "right.png");

    frisk   = new Image(Paths::images / "frisk.png");

}
