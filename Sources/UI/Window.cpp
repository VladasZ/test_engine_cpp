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
#include "ImageView.hpp"

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
ImageView *imageView;

GLuint texture;

Buffer *image;

void Window::setup() {
    
    GLfloat vertices[] = {
        // Positions           // Texture Coords
         0.5f,  0.5f, 0.0f,     1.0f, 0.0f, // Top Right
         0.5f, -0.5f, 0.0f,     1.0f, 1.0f, // Bottom Right
        -0.5f, -0.5f, 0.0f,     0.0f, 1.0f, // Bottom Left
        -0.5f,  0.5f, 0.0f,     0.0f, 0.0f  // Top Left
    };
    
    GLushort indices[] = {  // Note that we start from 0!
        0, 1, 3, 2  // Second Triangle
    };
    
    image = new Buffer(vertices, sizeof(vertices),
                       indices, sizeof(indices),
                       BufferConfiguration(3, 2));
    
    view = new View(0, 0, 100, 100);
    
    imageView = new ImageView(200, 0, 100, 100);
    imageView->setImage(&Image::test);
    
}

void Window::update() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    view->draw();
    
    glBindTexture(GL_TEXTURE_2D, texture);
    
    Image::test.bind();
    Shader::texture.use();

    image->draw();
    imageView->draw();

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
