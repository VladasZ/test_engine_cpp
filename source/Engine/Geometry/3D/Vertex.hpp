//
//  Vertex.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "String.hpp"
#include "Color.hpp"
#include "GL.hpp"

class Vertex MEMORY_MANAGED(Vertex) {
    
public:
    
    vec3 position;
    Color color;
    
    Vertex();
    Vertex(float x, float y, float z = 0, Color color = Color::white);
    Vertex(vec3 position, Color color = Color::white);
    
    String toString() const;
    
    static int bufferSize;
};
