//
//  Images.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 3/4/2019.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Paths.hpp"
#include "Images.hpp"

Images::Images() {
    cat = new Image(Paths::images_directory() + "cat.jpg");
}
