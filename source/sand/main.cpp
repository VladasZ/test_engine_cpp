
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <math.h>

//#include <glm/glm.hpp>


#include "Log.hpp"
#include "Matrix4.hpp"

#include "python_test.hpp"

using namespace std;

// Rotation
// [[-0.97046655 -0.22776104  0.07949577]
//  [ 0.23228709 -0.97119278  0.05317229]
//  [ 0.06509514  0.07006777  0.99541606]]

// Translation
// [[ -647.60141725]
//  [-3941.92610613]
//  [  707.33767687]]


// A = numpy.mat([[10.9651660037735,  -2077.46947601362, -1732.84852242907],
//                [-28.2892402763447, -2273.71719218789, -1731.04816455574],
//                [168.546146377346,  -2312.30780650516, -1737.13196368097],
//                [206.483925998667,  -2116.14490306792, -1738.21953548907]])

// B = numpy.mat([[-322.364164317381, -2013.94533203480, -1161.90839935893],
//                [-240.373482014670, -1832.26745097626, -1177.43805826682],
//                [-422.125535145367, -1749.48740754854, -1172.37193516593],
//                [-504.665226201976, -1931.16712127311, -1158.25483667854]])

int main() {

	Matrix4 transform = {
	    -0.97046655, -0.22776104, 0.07949577,  -647.60141725,
	     0.23228709, -0.97119278, 0.05317229, -3941.92610613,
	     0.06509514,  0.07006777, 0.99541606,   707.33767687,
	     0, 0, 0, 1
	};

	Matrix4 inversed = transform.inversed();


	Logvar(transform.to_string());
	Logvar(transform.inversed().to_string());

	vector<Vector3> a_ver = {
		{  10.9651660037735, -2077.46947601362, -1732.84852242907 },
		{ -28.2892402763447, -2273.71719218789, -1731.04816455574 },
		{ 168.546146377346,  -2312.30780650516, -1737.13196368097 },
		{ 206.483925998667,  -2116.14490306792, -1738.21953548907 }
	};

	vector<Vector3> transformed_a_ver;

	for (auto ver : a_ver)
		transformed_a_ver.push_back(transform * ver);

	for (auto ver : transformed_a_ver)
		Logvar(ver.to_string());


	for (auto ver : transformed_a_ver)
		Logvar((inversed * ver).to_string());


	auto station_b = transform * Vector3{};
  
	Logvar(station_b.to_string());
	Logvar(station_b.length());

  return 0;
}
