//
//  Polygon.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Vertex.hpp"
#include "Array.hpp"

class Polygon MEMORY_MANAGED(Polygon) {
    
public:
    
    Array<Vertex> vertices;
    Array<short> indices;
    
    float* vertexBuffer = nullptr;
    short* indexBuffer = nullptr;
    
    int vertexBufferSize;
    int indexBufferSize;
    
    Polygon();
    Polygon(Array<Vertex> vertices);
    
    void printBuffers();
    
protected:
    
    void createBuffers();
    void createVertexBuffer();
    void createIndexBuffer();
};
