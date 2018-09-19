//
//  Mesh.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Array.hpp"
#include "ColoredVertex.hpp"

#define USE_COLORED_MESH true

class Buffer;

class Mesh {
    
    Buffer* _buffer = nullptr;
    
    void _createBuffer();
    
public:
    
    Array<uint16_t> indices;
    
#if USE_COLORED_MESH
    Array<ColoredVertex> coloredVertices;
#else
    Array<Point3> vertices;
#endif
    
    virtual ~Mesh();
    
    void draw();
};
