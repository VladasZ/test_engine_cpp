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
#include "Shader.hpp"
#include "UI.hpp"
#include "Buffer.hpp"
#include "Image.hpp"
#include "FileManager.hpp"
#include "ImageView.hpp"
#include "Font.hpp"
#include "Glyph.hpp"

void sizeChanged(GLFWwindow* window, int width, int height);

#ifndef IOS
GLFWwindow * Window::window;
#endif

Size Window::size;
View * Window::rootView;
int Window::framesDrawn = 0;

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    Window::didTouch(xpos, ypos);
}

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
    glfwSetCursorPosCallback(window, cursor_position_callback);
    
    glewExperimental = GL_TRUE;
    if (glewInit()) { Error("Glew initialization failed"); }
    
#endif
    
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    Shader::initialize();
    Image::initialize();
    Font::initialize();
    
    glClearColor(0.5, 0.5, 0.5, 1);
    
    setup();
}

auto greenView = new View(10, 10, 300, 300);

void Window::didTouch(const int &x, const int &y) {
    cout << x << " " << y << endl;
    
    greenView->setCenter(Point(x, y));
}



void Window::setup() {
    rootView = new View(0, 0, Window::size.width, Window::size.height);
    
    
    greenView->color = Color::green;
    //testView->color.a = 0.5;
    
    auto redView = new View(5, 5, 100, 100);
    redView->color = Color::red;
    greenView->addSubview(redView);
    
    auto purpleView = new View(20, 20);
    purpleView->color = Color::purple;
    purpleView->autolayoutMask = Center;
    
    redView->addSubview(purpleView);
    
    rootView->addSubview(greenView);
    
    
    auto blueView = new View(200, 200);
    blueView->color = Color::blue;
    blueView->autolayoutMask = StickToBottom | StickToRight;
    
    rootView->addSubview(blueView);
    
    rootView->layout();
}

void Window::update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    rootView->drawSubviews();
    Window::framesDrawn++;
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    
    cout << "Window size changed to: " << width << " " << height << endl;
    
    Window::size.width  = width;
    Window::size.height = height;
    
    Shader::setupUiTranslation();
    rootView->frame = Rect(width, height);
    rootView->layout();
}

void Window::touchBegan(const TestEngine::Point &position) {
    
    cout << position.toString() << endl;
}

void Window::touchMoved(const TestEngine::Point &position) {
    
}
