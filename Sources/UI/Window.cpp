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

void windowSizeChanged(GLFWwindow* window, int width, int height);

UInt Window::shader;
UInt Window::vertexbuffer;
Size Window::size;

#ifndef IOS
GLFWwindow * Window::window;
#endif

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
    
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    sendData();
}

void Window::sendData() {
    
    static const GLfloat triangleData[] = {
        
        -1.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f,  1.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 1.0f
    };
    
    Buffer(sizeof(triangleData), triangleData);

    
    shader = ShaderManager::compileShaders();
    glUseProgram(shader);
}

void Window::update() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);
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
