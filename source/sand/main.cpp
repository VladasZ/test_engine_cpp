
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <math.h>

#include <Eigen/Dense>

#include "Log.hpp"
#include "Matrix4.hpp"

#include "python_test.hpp"

using namespace std;
using namespace Eigen;

constexpr float delay_to_angle(float delay) {
	return static_cast<float>(M_PI) * (delay - 4000) / 8333;
}

vector<Vector3> sensors_position = {
	{ +100, -100, 65 },
	{ -100, -100, 65 },
	{ -100, +100, 65 },
	{ +100, +100, 65 }
};

vector<vector<float>> delays = {
  { 3986, 2156 },
  { 4033, 2274 },
  { 3807, 2291 },
  { 3742, 2176 }
};

Vector3 ray(float angle1, float angle2) {
	Vector3 plane1 = { cos(angle1),           0, -sin(angle1) };
	Vector3 plane2 = {           0, cos(angle2),  sin(angle2) };
	return plane2.cross(plane1).normalize();
}

int main() {

	Matrix4 transform = {
		0, 0, 0, 1,
		0, 0, 1, 0,
		0, 1, 0, 0,
		1, 0, 0, 0
	};

	Matrix4 test = {
		1, 2, 3, 4, 
		5, 6, 7, 8,
		9, 10, 11, 12, 
		13, 14, 15, 16
	};

	Matrix4 result = transform * test;

	Logvar(result.to_string());

  
  return 0;
}
