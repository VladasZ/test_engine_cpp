//
//  Matrix4.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <math.h>

#include "Matrix4.hpp"


Matrix4::Matrix4() : Matrix4 {
    1, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 1, 0,
    0, 0, 0, 1
} { }

Matrix4::Matrix4(float value) {
	for (int i = 0; i < Matrix4::size; i++)
		*(&data[0][0] + i) = value;
}

Matrix4::Matrix4(const std::initializer_list<float>& list) {
    if (list.size() != Matrix4::size)
        throw "Matrix4 invalid initializer";
    std::copy(list.begin(), list.end(), &data[0][0]);
}

Matrix4 Matrix4::operator *(const Matrix4& mat) const {
	Matrix4 res;
	res.data[0][0] = data[0][0] * mat.data[0][0] + data[0][1] * mat.data[1][0] + data[0][2] * mat.data[2][0] + data[0][3] * mat.data[3][0];
	res.data[0][1] = data[0][0] * mat.data[0][1] + data[0][1] * mat.data[1][1] + data[0][2] * mat.data[2][1] + data[0][3] * mat.data[3][1];
	res.data[0][2] = data[0][0] * mat.data[0][2] + data[0][1] * mat.data[1][2] + data[0][2] * mat.data[2][2] + data[0][3] * mat.data[3][2];
	res.data[0][3] = data[0][0] * mat.data[0][3] + data[0][1] * mat.data[1][3] + data[0][2] * mat.data[2][3] + data[0][3] * mat.data[3][3];

	res.data[1][0] = data[1][0] * mat.data[0][0] + data[1][1] * mat.data[1][0] + data[1][2] * mat.data[2][0] + data[1][3] * mat.data[3][0];
	res.data[1][1] = data[1][0] * mat.data[0][1] + data[1][1] * mat.data[1][1] + data[1][2] * mat.data[2][1] + data[1][3] * mat.data[3][1];
	res.data[1][2] = data[1][0] * mat.data[0][2] + data[1][1] * mat.data[1][2] + data[1][2] * mat.data[2][2] + data[1][3] * mat.data[3][2];
	res.data[1][3] = data[1][0] * mat.data[0][3] + data[1][1] * mat.data[1][3] + data[1][2] * mat.data[2][3] + data[1][3] * mat.data[3][3];

	res.data[2][0] = data[2][0] * mat.data[0][0] + data[2][1] * mat.data[1][0] + data[2][2] * mat.data[2][0] + data[2][3] * mat.data[3][0];
	res.data[2][1] = data[2][0] * mat.data[0][1] + data[2][1] * mat.data[1][1] + data[2][2] * mat.data[2][1] + data[2][3] * mat.data[3][1];
	res.data[2][2] = data[2][0] * mat.data[0][2] + data[2][1] * mat.data[1][2] + data[2][2] * mat.data[2][2] + data[2][3] * mat.data[3][2];
	res.data[2][3] = data[2][0] * mat.data[0][3] + data[2][1] * mat.data[1][3] + data[2][2] * mat.data[2][3] + data[2][3] * mat.data[3][3];

	res.data[3][0] = data[3][0] * mat.data[0][0] + data[3][1] * mat.data[1][0] + data[3][2] * mat.data[2][0] + data[3][3] * mat.data[3][0];
	res.data[3][1] = data[3][0] * mat.data[0][1] + data[3][1] * mat.data[1][1] + data[3][2] * mat.data[2][1] + data[3][3] * mat.data[3][1];
	res.data[3][2] = data[3][0] * mat.data[0][2] + data[3][1] * mat.data[1][2] + data[3][2] * mat.data[2][2] + data[3][3] * mat.data[3][2];
	res.data[3][3] = data[3][0] * mat.data[0][3] + data[3][1] * mat.data[1][3] + data[3][2] * mat.data[2][3] + data[3][3] * mat.data[3][3];
	return res;
}

Matrix4 Matrix4::scale(float scale) {
	return  {
		scale,     0,     0, 0,
			0, scale,     0, 0,
			0,     0, scale, 0,
			0,     0,     0, 1
	};
}
 
Matrix4 Matrix4::translation(const Point3& location) {
	return {
		1, 0, 0, location.x,
		0, 1, 0, location.y,
		0, 0, 1, location.z,
		0, 0, 0,          1
	};
}

Matrix4 Matrix4::perspective(float fovy, float aspect, float zNear, float zFar) {

	float D2R = 3.14159265358f / 180.0f;
	float yScale = 1.0f / tan(D2R * fovy / 2.0f);
	float xScale = yScale / aspect;
	float nearmfar = zNear - zFar;

	return {
		xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, (zFar + zNear) / nearmfar, -1,
		0, 0, 2 * zFar*zNear / nearmfar, 0
	};
}
