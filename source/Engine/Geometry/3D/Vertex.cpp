//
//  Vertex.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Vertex.hpp"

Vertex::Vertex() :// position(vec3(0, 0, 0)), 
color(Color()) { }

Vertex::Vertex(float x, float y, float z, Color color) : //position(vec3(x, y, z)), 
color(color) { }

Vertex::Vertex(vec3 position, Color color) : position(position), color(color) { }

String Vertex::toString() const {
    return "x: "_s;//+ position.x + " y: " + position.y + " z: " + position.z;
}

int Vertex::bufferSize = 7;
