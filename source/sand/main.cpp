
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <math.h>

#include "Log.hpp"
#include "Matrix4.hpp"

using namespace std;

//constexpr 
float delay_to_angle(float delay) {
	Logvar(delay);
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
 
//plane1 = [+sympy.cos(a1), 0, -sympy.sin(a1)]
//# Normal to Y plane
//plane2 = [0, +sympy.cos(a2), +sympy.sin(a2)]

Vector3 ray(float angle1, float angle2) {
	Logvar(angle1);
	Logvar(angle2);
	Vector3 plane1 = { cos(angle1), 0,           -sin(angle2) };
	Vector3 plane2 = { 0,           cos(angle2),  sin(angle2) };
	return plane1.cross(plane2).normalize();
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
  
  //v0 = ray(tick2angle(samples[0][id * 2]), tick2angle(samples[0][id * 2 + 1]))
  // v1 = ray(tick2angle(samples[1][id * 2]), tick2angle(samples[1][id * 2 + 1]))
  // v2 = ray(tick2angle(samples[2][id * 2]), tick2angle(samples[2][id * 2 + 1]))
  // v3 = ray(tick2angle(samples[3][id * 2]), tick2angle(samples[3][id * 2 + 1]))

  
  return 0;
}
