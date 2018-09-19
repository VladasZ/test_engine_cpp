//
//  Point3.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <math.h>

#include "Point3.hpp"


Point3::Point3(float x, float y, float z) : x(x), y(y), z(z) { }

float Point3::lenght() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Point3& Point3::normalize() {
    auto ratio = 1 / lenght();
    this->x*=(ratio);
    this->y*=(ratio);
    this->z*=(ratio);
    return *this;
}
