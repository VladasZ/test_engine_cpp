//
//  Buffer.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/28/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Buffer.hpp"
#include "Debug.hpp"

Buffer::Buffer(GLfloat *vertData, GLuint vertSize)
:
vertData(vertData), vertSize(vertSize)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertSize, vertData, GL_STATIC_DRAW);
    glVertexAttribPointer(0,
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          3 * sizeof(GLfloat),
                          NULL);

    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

Buffer::Buffer(GLfloat *vertData, GLuint vertSize,
       GLushort *indData,  GLuint indSize)
:
vertData(vertData), vertSize(vertSize),
indData(indData), indSize(indSize)
{

    NOT_IMPLEMENTED;
}

void Buffer::draw() const {
 
    glBindVertexArray(VAO);
    
    if (indSize == 0) {
        
        glDrawArrays(drawMode, 0, 3);
    }
    else {
        
        NOT_IMPLEMENTED;
    }
    
    glBindVertexArray(0);

}
