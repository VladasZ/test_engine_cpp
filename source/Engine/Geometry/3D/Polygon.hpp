//
//  Polygon.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Vertex.hpp"
#include <vector>

class Polygon MEMORY_MANAGED(Polygon) {
    
public:
    
    std::vector<Vertex> vertices;
    std::vector<short> indices;
    
    float *vertexBuffer = nullptr;
    short *indexBuffer = nullptr;
    
    int vertexBufferSize;
    int indexBufferSize;
    
    Polygon();
    Polygon(std::vector<Vertex> vertices);
    
    void printBuffers();
    
protected:
    
    void createBuffers();
    void createVertexBuffer();
    void createIndexBuffer();
};
