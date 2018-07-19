//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Window.hpp"
#include "UI.hpp"
#include "GL.hpp"
#include "RootView.hpp"
#include "World.hpp"
#include "Time.hpp"
#include "Log.hpp"
#include "MemoryManager.hpp"
#include "Buffer.hpp"
#include "FrameBuffer.hpp"

void sizeChanged(GLFWwindow* window, int width, int height);

void Window::initialize(int width, int height) {
    
    size = Size(width, height);
    
#if GLFW
    
    glfwInit();
    
    glfwWindowHint(GLFW_SAMPLES, 16); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL
    
#if MAC_OS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
#endif
    
    window = glfwCreateWindow(width, height, "Test Engine", NULL, NULL);
    
    if (window == nullptr) {
        Error("GLFW window creation failed");
        return;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, sizeChanged);
    glfwSwapInterval(1); // Limit fps to 60

    glewExperimental = GL_TRUE;
    if (glewInit()) {
        Error("Glew initialization failed");
        return;
    }

    const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    screenResolution = { (float)mode->width, (float)mode->height };
    
    Log("Screen resolution: " << (int)screenResolution.width << "x" << (int)screenResolution.height);

#endif
    
    //GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    
    Input::initialize();
    Shader::initialize();
    Image::initialize();
    Font::initialize();
    Buffer::initialize();

    rootFrameBuffer = new FrameBuffer(screenResolution);
    
    GL(glClearColor(0.5, 0.5, 0.5, 1));
    
    setup(); 
}

void Window::setup() {
    rootView = new RootView({ Window::size.width, Window::size.height });
    
    rootView->setup();
    rootView->layout();
    
    world.setup();
}

void Window::onDebugTick() {
    rootView->debugInfoView->update();
}

void Window::update() {
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    
    rootView->draw();

    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
    resetViewport();
    Shader::uiTexture.use();
    rootFrameBuffer->getImage()->bind();
    Buffer::rootUIBuffer->draw();
    GL(glBindTexture(GL_TEXTURE_2D, 0));

    FPS = 1000000000 / Time::interval();
    
    Window::framesDrawn++;
    
    if (Window::framesDrawn % 1 == 0) onDebugTick();
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    Window::size = Size(width, height);
    rootView->setFrame(Rect(width, height));
    rootFrameBuffer->clear();
    Buffer::windowSizeChanged();
    update();
    GL(glfwSwapBuffers(Window::window));
}

void Window::resetViewport() {
    glViewport(0, 0, size.width, size.height);
}
