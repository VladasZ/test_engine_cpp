//
//  TestEngine.h
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//


#include "TestEngine.h"
#include "GL/GL.hpp"
#include "Window.hpp"


void runTestEngine() {

	Window::initialize();

	do {
		glfwPollEvents();

		Window::update();

		glfwSwapBuffers(Window::window);
	} while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0);
}
