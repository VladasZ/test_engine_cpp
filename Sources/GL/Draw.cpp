//
//  Draw.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/30/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Draw.hpp"
#include "GL.hpp"
#include "Shader.hpp"
#include "Color.hpp"


void Draw::rect(const Rect &rect) {
    
    Shader::simple.use();
    
    float vertices[4 * 3] = { rect.origin.x, rect.origin.y, 0,
                              rect.origin.x + rect.size.width, rect.origin.y, 0,
                              rect.origin.x, rect.origin.y + rect.size.height, 0,
                              rect.origin.x + rect.size.width, rect.origin.y + rect.size.height, 0};
    
    static GLushort indices[] = { 0, 1, 2, 3 };

    
    GLuint bufferID;
    glGenBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * 3,
                 vertices, GL_STATIC_DRAW);
    
    GLuint bufferID2;
    glGenBuffers(1, &bufferID2);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * 4,
                 indices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          3 * sizeof(float),
                          0);
    
    
    Color::blue.setToUniform(Shader::simple.uniformColor);

    
    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_SHORT, 0);
}
