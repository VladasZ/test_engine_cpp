//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Window.hpp"
#include "GL.hpp"
#include "Log.hpp"
#include "Platform.h"
#include "Buffer.hpp"
#include "Cube.hpp"
#include "View.hpp"
#include "Color.hpp"
#include "Triangle.hpp"
#include <glm/gtc/matrix_transform.hpp>

void windowSizeChanged(GLFWwindow* window, int width, int height);

#ifndef IOS
GLFWwindow * Window::window;
#endif

Size Window::size;


void Window::initialize(int width, int height) {
    
    size = Size(width, height);
    
#ifndef IOS
    
    glfwInit();
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
    
    window = glfwCreateWindow(width, height, "Test Engine", NULL, NULL);
    
    if (window == nullptr) { Error("GLFW window creation failed"); return; }
    
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, windowSizeChanged);
    
    glewExperimental = true;
    if (glewInit()) { Error("Glew initialization failed"); }
    
#endif
    
    glEnable(GL_DEPTH_TEST);
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    Shader::initialize();
    
    sendData();
}

void Window::sendData() {
    
    Triangle cube;
    
    auto vertexBuffer = Buffer(cube.vertexBufferSize,
                               cube.vertexBuffer,
                               GL_ARRAY_BUFFER);
    
    vertexBuffer.setVertexPointer(0);
    vertexBuffer.setColorPointer(1);
    
    auto indexBuffer = Buffer(cube.indexBufferSize,
                              cube.indexBuffer,
                              GL_ELEMENT_ARRAY_BUFFER);
    
    Shader::colorVertices.use();
    
//    Rect rect(0, 0, 1, 1);
//    
//    Shader::simple.use();
//    
//    float vertices[4 * 3] = { rect.origin.x, rect.origin.y, 0,
//        rect.origin.x + rect.size.width, rect.origin.y, 0,
//        rect.origin.x, rect.origin.y + rect.size.height, 0,
//        rect.origin.x + rect.size.width, rect.origin.y + rect.size.height, 0};
//    
//    static GLushort indices[] = { 0, 1, 2, 3 };
//    
//    
//    GLuint bufferID;
//    glGenBuffers(1, &bufferID);
//    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * 3,
//                 vertices, GL_STATIC_DRAW);
//    
//    GLuint bufferID2;
//    glGenBuffers(1, &bufferID2);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID2);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * 4,
//                 indices, GL_STATIC_DRAW);
//    
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0,
//                          3,
//                          GL_FLOAT,
//                          GL_FALSE,
//                          3 * sizeof(float),
//                          0);
//    
//    
//    Color::blue.setToUniform(Shader::simple.uniformColor);

}

void Window::didTouch(const int &x, const int &y) {
    
    cout << x << " " << y << endl;
}

void Window::update() {
    
   // glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_SHORT, 0);

    
    static float rotationX = 0.f;
    static float rotationY = 0.f;
    static float fieldOfView = 100.0f;
    
    static float nearPlane = 1.0f;
    static float farPlane = 5.0f;
    
    rotationY += 0.5f;
    
    mat4 projection = perspective(fieldOfView, size.width / size.height , nearPlane, farPlane);
    mat4 translationProjection = translate(projection, vec3(0, 0, -3.0f));
    mat4 fullTranslation = rotate(translationProjection, rotationX , vec3(1.0f, 0.0f, 0.0f));
    fullTranslation = rotate(fullTranslation, rotationY , vec3(0.0f, 1.0f, 0.0f));
    
    
    GLint transformLocation = glGetUniformLocation(Shader::colorVertices.program, "transformMatrix");
    
    glUniformMatrix4fv(transformLocation, 1, false, &fullTranslation[0][0]);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
}

#ifndef IOS

void windowSizeChanged(GLFWwindow* window, int width, int height) {
    
    Window::size.width  = width;
    Window::size.height = height;
}

#endif

Float Window::pixelToGLX(Float x) {
    
    Float pixel = 2 / size.width;
    return -1 + x * pixel;
}

Float Window::pixelToGLY(Float y) {
    
    Float pixel = 2 / size.height;
    return -1 + y * pixel;
}

Float Window::pixelFromGLX(Float x) {
    
    Float pixel = 2 / size.width;
    return (x + 1) / pixel;
}

Float Window::pixelFromGLY(Float y) {
    
    Float pixel = 2 / size.height;
    return (y + 1) / pixel;
}

#pragma mark - Touches

void Window::touchBegan(const TestEngine::Point &position) {
    
    cout << position.toString() << endl;
}
