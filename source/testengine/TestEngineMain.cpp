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

//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"

#include "Matrix4.hpp"

void glmTest() {
    Matrix4 mat = Matrix4::rotation(45.0f, {1, 0, 0});
    Logvar(mat.toString());
    return;
}

int testEngineMain() {
    
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
