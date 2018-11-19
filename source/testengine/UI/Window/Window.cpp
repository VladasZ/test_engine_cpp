//
//  Window.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Window.hpp"
#include "GL.hpp"
#include "RootView.hpp"
#include "World.hpp"
#include "Time.hpp"
#include "Log.hpp"
#include "FrameBuffer.hpp"
#include "GlobalEvents.hpp"
#include "Scene.hpp"
#include "Buffer.hpp"

void sizeChanged(GLFWwindow* window, int width, int height);

void Window::initialize(int width, int height) {

    size = Size((float)width, (float)height);

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
		throw "GLFW window creation failed";
    }

    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, sizeChanged);
    glfwSwapInterval(1); // Limit fps to 60

    glewExperimental = GL_TRUE;
    if (glewInit()) {
        Error("Glew initialization failed");
		throw "Glew initialization failed";
    }

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    screenResolution = { (float)mode->width, (float)mode->height };
    
    Log("Screen resolution: " << (int)screenResolution.width << "x" << (int)screenResolution.height);

#endif

    //GL(glEnable(GL_DEPTH_TEST));
    GL(glEnable(GL_BLEND));
    //GL(glEnable(GL_ALPHA_TEST));
    GL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
   // GL(glLineWidth(1000));
    
    Input::initialize();
    Shader::initialize();
    Image::initialize();
    Font::initialize();
    Buffer::initialize();

    rootFrameBuffer = new FrameBuffer(screenResolution);

    setup(); 

	Events::onScreenSizeChange(screenResolution);
}

void Window::setup() {
    rootView = new RootView({ Window::size.width, Window::size.height });
	rootView->_frameBuffer = rootFrameBuffer;
    rootView->setup();
    rootView->layout();
    rootView->_frameBuffer->clear();

	setScene(new Scene());
}

void Window::update() {
    GL::setClearColor(C::gray);
    GL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

	if (currentScene) {
		GL(glEnable(GL_DEPTH_TEST));
		currentScene->draw();
	}

	GL(glDisable(GL_DEPTH_TEST));

    rootFrameBuffer->clear();
    rootView->draw();

	GL(glViewport(0, 0, (GLsizei)size.width, (GLsizei)size.height));

    GL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
	GL(glViewport(0, 0, (GLsizei)size.width, (GLsizei)size.height));
    Shader::uiTexture.use();
    rootFrameBuffer->getImage()->bind();
    Buffer::rootUIBuffer->draw();
    GL(glBindTexture(GL_TEXTURE_2D, 0));

    FPS = 1000000000 / Time::interval();

    Window::framesDrawn++;
	Events::frame_drawn();
}

void Window::setScene(Scene* scene) {
	scene->setup();
	currentScene = scene;
}

void Window::sizeChanged(GLFWwindow* window, int width, int height) {
    Window::size = Size((float)width, (float)height);
    rootView->setFrame(Rect((float)width, (float)height));
    rootFrameBuffer->clear();
    Buffer::windowSizeChanged();
	Events::onScreenSizeChange(size);
    update();
    GL(glfwSwapBuffers(Window::window));
}