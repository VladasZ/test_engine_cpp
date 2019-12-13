//
//  GLTest.cpp
//  test_engine
//
//  Created by Vladas Zakrevskis on 03/06/2019.
//  Copyright © 2019 vz. All rights reserved.
//

#include "GLTest.hpp"
#include "Assets.hpp"
#include "GLWrapper.hpp"
#include "OpenGLHeaders.hpp"
#include "GLDebug.hpp"

using namespace te;


void Test::drawTriangle() {

//    GLfloat vVertices[] = { 0.0f,  0.5f, 0.0f,
//                           -0.5f, -0.5f, 0.0f,
//                            0.5f, -0.5f, 0.0f };
//
//    // Clear the color buffer
//   // glClear(GL_COLOR_BUFFER_BIT);
//    // Use the program object
//
//    Assets::shaders->simple->use();
//
//    //glUseProgram(userData->programObject);
//    // Load the vertex data
//    GL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices));
//    GL(glEnableVertexAttribArray(0));
//    GL(glDrawArrays(GL_TRIANGLES, 0, 3));

    GL(glBegin(GL_QUADS)); // Start drawing a quad primitive

    GL((-1.0f, -1.0f, 0.0f)); // The bottom left corner
    GL(glVertex3f(-1.0f, 1.0f, 0.0f)); // The top left corner
    GL(glVertex3f(1.0f, 1.0f, 0.0f)); // The top right corner
    GL(glVertex3f(1.0f, -1.0f, 0.0f)); // The bottom right corner

    GL(glEnd());

}



