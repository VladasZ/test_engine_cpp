//
//  TestEngineMain.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "TestEngineMain.h"
#include "GL/GL.hpp"
#include "Window.hpp"
#include "Debug.hpp"

void testEngineMain() {
	Window::initialize(800, 800);
	do {
		GL(glfwPollEvents());
		Window::update();
		GL(glfwSwapBuffers(Window::window));
	} while (
		glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0
	);
}
