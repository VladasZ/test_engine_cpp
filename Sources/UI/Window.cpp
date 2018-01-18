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
    
    //glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    Shader::initialize();
    Image::initialize();
    
    glClearColor(0.5, 0.5, 0.5, 1);
    
    setup();
}

void Window::didTouch(const int &x, const int &y) {
    
    cout << x << " " << y << endl;
}

Font *testFont;

View *view;
ImageView *fontImageView;
ImageView *catImageView;
ImageView *slowImageView;
ImageView *palmImageView;

void Window::setup() {
    
    testFont = new Font("Fonts/SF.otf");
    
    auto fontImage = testFont->glyphForChar('S')->image;
    
    Image::cat = testFont->glyphForChar('g')->image;
    Image::palm = testFont->glyphForChar('T')->image;
    Image::slow = testFont->glyphForChar('q')->image;
    
    view = new View(0, 0, 100, 100);
    view->color = Color::green;
    
    fontImageView = new ImageView(200, 0, 100, 150);
    fontImageView->setImage(Image::palm);
    fontImageView->autolayoutMask = StickToTop | CenterHorizontally;
    
    catImageView = new ImageView(400, 0, 110, 150);
    catImageView->setImage(Image::cat);
    catImageView->autolayoutMask = StickToRight | StickToBottom;
    
    slowImageView = new ImageView(0, 0, 200, 200);
    slowImageView->setImage(Image::slow);
    slowImageView->autolayoutMask = StickToBottom | StickToLeft;
    
    palmImageView = new ImageView(0, 0, fontImage->width, fontImage->height);
    palmImageView->setImage(fontImage);
    palmImageView->autolayoutMask = CenterVertically | CenterHorizontally;
    
}

void Window::update() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    view->draw();
    
    fontImageView->draw();
    catImageView->draw();
    slowImageView->draw();
    palmImageView->draw();
    
    Window::framesDrawn++;
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    
    cout << "Window size changed to: " << width << " " << height << endl;
    
    Window::size.width  = width;
    Window::size.height = height;
    
    Shader::setupUiTranslation();
}

void Window::touchBegan(const TestEngine::Point &position) {
    
    cout << position.toString() << endl;
}

void Window::touchMoved(const TestEngine::Point &position) {
    
}
