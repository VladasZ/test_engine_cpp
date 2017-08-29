//
//  Polygon.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Polygon.hpp"

//Public

Polygon::Polygon() {
    
}

Polygon::Polygon(vector<Vertex> vertices) : vertices(vertices) {
    
    createBuffers();
}

//Private

void Polygon::createBuffers() {
    
    createVertexBuffer();
    createIndexBuffer();
}

void Polygon::createVertexBuffer() {
    
    cout << Vertex::bufferSize << endl;
    
    vertexBuffer = new float[Vertex::bufferSize * vertices.size()];
    vertexBufferSize = Vertex::bufferSize * sizeof(float) * (int)vertices.size();
    
    cout << vertices.size() << endl;
    
    for(int i = 0; i < vertices.size(); i++) {
        
        Vertex vertex = vertices[i];
        float *vertexPosition = vertexBuffer + Vertex::bufferSize * i;
        
        vertexPosition[0] = vertex.position.x;
        vertexPosition[1] = vertex.position.y;
        vertexPosition[2] = vertex.position.z;
        
        vertexPosition[3] = vertex.color.r;
        vertexPosition[4] = vertex.color.g;
        vertexPosition[5] = vertex.color.b;
        vertexPosition[6] = vertex.color.a;
    }
}

void Polygon::createIndexBuffer() {
    
    indexBuffer = indices.data();
    indexBufferSize = (int)indices.size() * sizeof(GLushort);
}

void Polygon::printBuffers() {
    
    for(int i = 0; i < indices.size(); i++) {
        
        cout << indexBuffer[i] << " ";
    }
    
    cout << endl;
    
    for(int i = 0; i < vertices.size() * Vertex::bufferSize; i++) {
        
        cout << vertexBuffer[i] << " ";
    }
}
