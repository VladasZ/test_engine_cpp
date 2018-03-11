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

void testEngineMain() {
    
#if MEMORY_TEST
    memoryTest();
    MemoryManager::printDump();
    return;
#endif
    
	Window::initialize(1200, 760);

	do {
		GL(glfwPollEvents());

		Window::update();

		GL(glfwSwapBuffers(Window::window));
	} while (glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0);
#if MEMORY_TRACKING
    MemoryManager::printDump();
#endif
}
