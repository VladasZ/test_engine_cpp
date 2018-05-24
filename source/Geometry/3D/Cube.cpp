//
//  Cube.cpp
//  OpenGL Test
//
//  Created by Vladas Zakrevskis on 5/27/17.
//  Copyright © 2017 Vladas Zakrevskis. All rights reserved.
//

#include "Cube.hpp"

Cube::Cube() {
    
    vertices = {
        
        Vertex(-1.0f, +1.0f, +1.0f, Color::random()),
        Vertex(+1.0f, +1.0f, +1.0f, Color::random()),
        Vertex(+1.0f, +1.0f, -1.0f, Color::random()),
        Vertex(-1.0f, +1.0f, -1.0f, Color::random()),
        
        Vertex(-1.0f, +1.0f, -1.0f, Color::random()),
        Vertex(+1.0f, +1.0f, -1.0f, Color::random()),
        Vertex(+1.0f, -1.0f, -1.0f, Color::random()),
        Vertex(-1.0f, -1.0f, -1.0f, Color::random()),
        
        Vertex(+1.0f, +1.0f, -1.0f, Color::random()),
        Vertex(+1.0f, +1.0f, +1.0f, Color::random()),
        Vertex(+1.0f, -1.0f, +1.0f, Color::random()),
        Vertex(+1.0f, -1.0f, -1.0f, Color::random()),
        
        Vertex(-1.0f, +1.0f, +1.0f, Color::random()),
        Vertex(-1.0f, +1.0f, -1.0f, Color::random()),
        Vertex(-1.0f, -1.0f, -1.0f, Color::random()),
        Vertex(-1.0f, -1.0f, -1.0f, Color::random()),
        
        Vertex(+1.0f, +1.0f, +1.0f, Color::random()),
        Vertex(-1.0f, +1.0f, +1.0f, Color::random()),
        Vertex(-1.0f, -1.0f, +1.0f, Color::random()),
        Vertex(+1.0f, -1.0f, +1.0f, Color::random()),
        
        Vertex(+1.0f, -1.0f, -1.0f, Color::random()),
        Vertex(-1.0f, -1.0f, -1.0f, Color::random()),
        Vertex(-1.0f, -1.0f, +1.0f, Color::random()),
        Vertex(+1.0f, -1.0f, +1.0f, Color::random())
    };
    
    indices = {
        
        0,  1,  2,  0,  2,  3, // Top
        4,  5,  6,  4,  6,  7, // Front
        8,  9, 10,  8, 10, 11, // Right
        12, 13, 14, 12, 14, 15, // Left
        16, 17, 18, 16, 18, 19, // Back
        20, 22, 21, 20, 23, 22, // Bottom
    };
    
    createBuffers();
}
