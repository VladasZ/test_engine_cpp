//
//  View.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "View.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"

View::View(Float x, Float y, Float width, Float height) : frame(Rect(x, y, width, height)) {
    
    buffer = new Buffer(*frame.getData());
    buffer->drawMode = GL_TRIANGLE_STRIP;
}

View::View(Float width, Float height) : View(0, 0, width, height) {
    
}

void View::draw() {
    
    for (int i = (int)subviews.size() - 1; i >= 0; i--)
        subviews[i]->draw();
    
    Shader::simple.use();
    Shader::simple.setUniformColor(color);
    buffer->draw();
}

void View::layout() {
    
}

void View::addSubview(View *view) {
    
    subviews.push_back(view);
}
