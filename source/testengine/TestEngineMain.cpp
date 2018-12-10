//
//  TestEngineMain.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/20/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Log.hpp"

#include "TestEngineMain.h"
#include "GL/GL.hpp"
#include "Window.hpp"
#include "Debug.hpp"

#include "Assimp.hpp"
#include "Matrix4.hpp"

int test_engine_main() {
    
	Window::initialize(1200, 880);
	do {
		GL(glfwPollEvents());
		Window::update();
		GL(glfwSwapBuffers(Window::window));
	} while (
		glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0
	);

	return 0;
}
