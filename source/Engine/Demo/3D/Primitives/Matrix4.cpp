//
//  Matrix4.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include <math.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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

String Matrix4::toString() const {
	return Matrix4::bufferToString(&data[0][0]);
}

String Matrix4::bufferToString(const float* buf) {

	return std::string() +
		std::to_string(buf[0]) + " " + std::to_string(buf[4]) + " " + std::to_string(buf[8])  + " " + std::to_string(buf[12]) + "\n" +
		std::to_string(buf[1]) + " " + std::to_string(buf[5]) + " " + std::to_string(buf[9])  + " " + std::to_string(buf[13]) + "\n" +
		std::to_string(buf[2]) + " " + std::to_string(buf[6]) + " " + std::to_string(buf[10]) + " " + std::to_string(buf[14]) + "\n" +
		std::to_string(buf[3]) + " " + std::to_string(buf[7]) + " " + std::to_string(buf[11]) + " " + std::to_string(buf[15]);
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
		1,					 0,			 0, 0,
		0,					 1,			 0, 0,
		0,					 0,			 1, 0,
		location.x, location.y, location.z, 1
	};
}

Matrix4 Matrix4::rotation(float angle, const Point3& in) {
    return glm::rotate(glm::mat4(), angle, {in.x, in.y, in.z});
}

Matrix4 Matrix4::perspective(float fovy, float aspect, float zNear, float zFar) {

	float const tanHalfFovy = tan(fovy / 2.0f);

	Matrix4 result(0.0f);
	result.data[0][0] = 1.0f / (aspect * tanHalfFovy);
	result.data[1][1] = 1.0f / (tanHalfFovy);
	result.data[2][3] = -1.0f;

//#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
//	Result[2][2] = zFar / (zNear - zFar);
//	Result[3][2] = -(zFar * zNear) / (zFar - zNear);
//#		else
	result.data[2][2] = -(zFar + zNear) / (zFar - zNear);
	result.data[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);
//#		endif

	return result;
}
