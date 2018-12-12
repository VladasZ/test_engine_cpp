
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

  auto r01 = (sensors_position[0] - sensors_position[1]).length();
  auto r02 = (sensors_position[0] - sensors_position[2]).length();
  auto r03 = (sensors_position[0] - sensors_position[3]).length();
  auto r12 = (sensors_position[1] - sensors_position[2]).length();
  auto r13 = (sensors_position[1] - sensors_position[3]).length();
  auto r23 = (sensors_position[2] - sensors_position[3]).length();

  auto v0 = ray(delay_to_angle(delays[0][0]), delay_to_angle(delays[0][1]));
  auto v1 = ray(delay_to_angle(delays[1][0]), delay_to_angle(delays[1][1]));
  auto v2 = ray(delay_to_angle(delays[2][0]), delay_to_angle(delays[2][1]));
  auto v3 = ray(delay_to_angle(delays[3][0]), delay_to_angle(delays[3][1]));

  Logvar(v0.to_string());
  Logvar(v1.to_string());
  Logvar(v2.to_string());
  Logvar(v3.to_string());

  auto v01 = v0.dot(v1);
  auto v02 = v0.dot(v2);
  auto v03 = v0.dot(v3);
  auto v12 = v1.dot(v2);
  auto v13 = v1.dot(v3);
  auto v23 = v2.dot(v3);
  
  Logvar(acos(v01) * 180 / M_PI);
  Logvar(acos(v02) * 180 / M_PI);
  Logvar(acos(v03) * 180 / M_PI);
  Logvar(acos(v12) * 180 / M_PI);
  Logvar(acos(v13) * 180 / M_PI);
  Logvar(acos(v23) * 180 / M_PI);


  Matrix3d A;
  Vector3d b;
  A << 1, 2, 3, 
	   4, 5, 6, 
	   7, 8, 10;
  b << 3, 3, 4;
  cout << "Here is the matrix A:\n" << A << endl;
  cout << "Here is the vector b:\n" << b << endl;
  Vector3d x = A.colPivHouseholderQr().solve(b);
  cout << "The solution is:\n" << x << endl;

  python_test();
  
  return 0;
}
