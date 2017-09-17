//
//  Rect.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Rect.hpp"
#include "Window.hpp"

Rect::Rect(Float width, Float height)
: size(Size(width, height))
{
    
}


Rect::Rect(Float x, Float y, Float width, Float height)
: origin(Point(x, y)), size(Size(width, height))
{
    
}

BufferData Rect::getData() const {
    
    GLfloat rect[] = {
        Window::pixelToGLX(origin.x),              Window::pixelToGLY(origin.y),               0.0f,
        Window::pixelToGLX(origin.x),              Window::pixelToGLY(size.height + origin.y), 0.0f,
        Window::pixelToGLX(size.width + origin.x), Window::pixelToGLY(size.height + origin.y), 0.0f,
        Window::pixelToGLX(size.width + origin.x), Window::pixelToGLY(origin.y),               0.0f
    };
    
    GLushort indices[] = { 0, 1, 2, 3 };
    
    return BufferData(rect,    sizeof(rect),
                      indices, sizeof(indices));
}
