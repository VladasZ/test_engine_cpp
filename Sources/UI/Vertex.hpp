//
//  Vertex.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "GL.hpp"
#include "Types.h"
#include "Color.hpp"

class Vertex {
    
public:
    
    vec3 position;
    Color color;
    
    Vertex();
    Vertex(Float x, Float y, Float z = 0, Color color = Color::white);
    Vertex(vec3 position, Color color = Color::white);
    
    string toString();
    
    static int bufferSize;
};
