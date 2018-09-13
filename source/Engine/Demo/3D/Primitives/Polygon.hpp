//
//  Polygon.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point3.hpp"
#include "Array.hpp"

class Buffer;

class Polygon {
    
    Buffer* _buffer = nullptr;
    
    void _createBuffer();
    
public:
    
    Array<uint16_t> indices;
    Array<Point3> vertices;
    
    virtual ~Polygon();
    
    void draw();
};
