//
//  Size.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Size.hpp"

Size::Size(float width, float height) : width(width), height(height) { }

Point Size::center() const {
    return Point(width / 2, height / 2);
}
