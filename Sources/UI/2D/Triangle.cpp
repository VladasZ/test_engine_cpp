//
//  Triangle.cpp
//  OpenGL Test
//
//  Created by Vladas Zakrevskis on 5/25/17.
//  Copyright © 2017 Vladas Zakrevskis. All rights reserved.
//

#include "Triangle.hpp"

Triangle::Triangle() {
        
    vertices = {
        Vertex(0 ,  1),
        Vertex(-1, -1),
        Vertex(1 , -1)
    };
    
    indices = { 0, 1, 2 };
    
    createBuffers();
}
