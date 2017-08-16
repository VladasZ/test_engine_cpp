#include <iostream>
#include <Windows.h>
#include <Tools\Tools.hpp>
#include "glfw3.h"

using namespace std;

int main() {

	Info("rglooooorglak!");


	glfwInit();
	glfwCreateWindow(100, 100, "Elite Engine", NULL, NULL);

	Sleep(100000);
	return 0;
}