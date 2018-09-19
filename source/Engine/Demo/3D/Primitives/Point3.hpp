//
//  Point3.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "String.hpp"

class Point3 {
    
public:
    
    float x = 0;
    float y = 0;
    float z = 0;
    
    Point3() = default;
    Point3(float x, float y, float z);

    float lenght() const;
    
    Point3& normalize();
};

