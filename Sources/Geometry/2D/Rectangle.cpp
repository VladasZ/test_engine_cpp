//
//  Rectangle.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/31/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Rectangle.hpp"
#include "Window.hpp"

Rectangle::Rectangle() {
    
    vertices = {
        
        Vertex(0,   0,   0.2, Color::random()),
        Vertex(0,   100, 0.2, Color::random()),
        Vertex(100, 100, 0.2, Color::random()),
        Vertex(100, 0,   0.2, Color::random())
    };
    
    indices = { 0, 1, 3, 1, 3, 2 };
    
    createBuffers();
}
