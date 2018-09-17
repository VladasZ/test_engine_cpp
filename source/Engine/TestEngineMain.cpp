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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Matrix4.hpp"


void testEngineMain() {

	glm::mat4 rgloc; 
	
	auto glmResult = glm::perspective<float>(0.7f, 1, 0.1, 100);

	Matrix4 mat = Matrix4::perspective(0.7f, 1, 0.1, 100);

	Logvar(Matrix4::bufferToString(&glmResult[0][0]));
	Logvar(mat.toString());

	Log(sizeof(rgloc));
	Log(sizeof(mat));


	//return;


	Window::initialize(1200, 880);
	do {
		GL(glfwPollEvents());
		Window::update();
		GL(glfwSwapBuffers(Window::window));
	} while (
		glfwGetKey(Window::window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(Window::window) == 0
	);
}
