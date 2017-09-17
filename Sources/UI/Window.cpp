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
#include "System.hpp"
#include "Rectangle.hpp"
#include "Time.hpp"
#include "System.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.hpp"
#include "UI.hpp"
#include "Buffer.hpp"

void windowSizeChanged(GLFWwindow* window, int width, int height);

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
    glfwSetWindowSizeCallback(window, windowSizeChanged);
    
    glewExperimental = GL_TRUE;
    if (glewInit()) { Error("Glew initialization failed"); }
    
#endif
    
    glEnable(GL_DEPTH_TEST);
    
    Shader::initialize();
    
    setup();
}

void Window::didTouch(const int &x, const int &y) {
    
    cout << x << " " << y << endl;
}


void Window::setup() {
   
    rootView = new View(size.width, size.height);
    rootView->color = Color::white;


    View *view1 = new View(100, 100);
    view1->color = Color::orange;
    
    View *view2 = new View(200, 200, 10, 10);
    view2->color = Color::red;
    
    rootView->addSubview(view1);
    rootView->addSubview(view2);

}

void Window::update() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    rootView->draw();
}


#ifndef IOS

void windowSizeChanged(GLFWwindow* window, int width, int height) {
    
    cout << "Window size changed to: " << width << " " << height << endl;
    
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
    return 1 - y * pixel;
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
