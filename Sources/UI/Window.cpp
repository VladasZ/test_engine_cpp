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
#include "View.hpp"
#include "Color.hpp"
#include "System.hpp"
#include "Time.hpp"
#include "System.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.hpp"
#include "UI.hpp"
#include "Buffer.hpp"
#include "Image.hpp"
#include "FileManager.hpp"

void sizeChanged(GLFWwindow* window, int width, int height);

#ifndef IOS
GLFWwindow * Window::window;
#endif

Size Window::size;
View * Window::rootView;

void Window::initialize(int width, int height) {
    
    size = Size(width, height);
    
#ifndef IOS
    
    glfwInit();
    
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
    
#if MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
#endif
    
    window = glfwCreateWindow(width, height, "Test Engine", NULL, NULL);
    
    if (window == nullptr) { Error("GLFW window creation failed"); return; }
    
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, sizeChanged);
    
    glewExperimental = GL_TRUE;
    if (glewInit()) { Error("Glew initialization failed"); }
    
#endif
    
    glEnable(GL_DEPTH_TEST);
    
    Shader::initialize();
    Image::initialize();
    
    setup();
}

void Window::didTouch(const int &x, const int &y) {
    
    cout << x << " " << y << endl;
}

View *view;
GLuint texture;
GLuint VBO, VAO, EBO;

void Window::setup() {
    
    GLfloat vertices[] = {
        // Positions          // Colors           // Texture Coords
         0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // Top Right
         0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 1.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 1.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 0.0f  // Top Left
    };
    
    GLuint indices[] = {  // Note that we start from 0!
        0, 1, 3, 2  // Second Triangle
    };
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    // Color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    // TexCoord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0); // Unbind VAO
    
    view = new View(0, 0, 100, 100);
}

void Window::update() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    view->draw();
    
    glBindTexture(GL_TEXTURE_2D, texture);
    
    Image::test.bind();
    Shader::texture.use();

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    
    cout << "Window size changed to: " << width << " " << height << endl;
    
    Window::size.width  = width;
    Window::size.height = height;
    
    Shader::setupUiTranslation();
}

#pragma mark - Touches

void Window::touchBegan(const TestEngine::Point &position) {
    
    cout << position.toString() << endl;
}

void Window::touchMoved(const TestEngine::Point &position) {
    
}
