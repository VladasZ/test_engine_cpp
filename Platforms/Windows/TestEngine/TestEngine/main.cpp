//
//  main.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/17/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "TestEngine.h"

int main() {

	Window::initialize();

	for (;;) {

		Window::update();
		glfwSwapBuffers(Window::window);
		glfwPollEvents();
	}

	return 0;
}
