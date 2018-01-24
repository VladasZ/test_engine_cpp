//
//  Polygon.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "Vertex.hpp"

class Polygon MEMORY_MANAGED(Polygon) {
    
public:
    
    vector<Vertex> vertices;
    vector<GLushort> indices;
    
    GLfloat *vertexBuffer = nullptr;
    GLushort *indexBuffer = nullptr;
    
    int vertexBufferSize;
    int indexBufferSize;
    
    Polygon();
    Polygon(vector<Vertex> vertices);
    
    void printBuffers();
    
protected:
    
    void createBuffers();
    void createVertexBuffer();
    void createIndexBuffer();
};
