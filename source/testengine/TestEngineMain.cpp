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
#include "Screen.hpp"
#include "Debug.hpp"

#include "Matrix4.hpp"

int test_engine_main() {
    
    Screen::initialize({ 1200, 800 });
	do {
		GL(glfwPollEvents());
        Screen::update();
        GL(glfwSwapBuffers(Screen::glfw_window));
	} while (
        glfwGetKey(Screen::glfw_window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(Screen::glfw_window) == 0
	);

	return 0;
}
