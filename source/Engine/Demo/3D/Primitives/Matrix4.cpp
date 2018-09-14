//
//  Matrix4.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

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
 
Matrix4 Matrix4::perspective(float fovy, float aspect, float zNear, float zFar) {

	float const tanHalfFovy = tan(fovy / 2.0f);

	Matrix4 result = 0;
	result.data[0][0] = 1.0f / (aspect * tanHalfFovy);
	result.data[1][1] = 1.0f / (tanHalfFovy);
	result.data[2][3] = -1.0f;

#	//	if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
	result.data[2][2] = zFar / (zNear - zFar);
	result.data[3][2] = -(zFar * zNear) / (zFar - zNear);
//#		else
//	Result[2][2] = -(zFar + zNear) / (zFar - zNear);
//	Result[3][2] = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
//#		endif

	return result;
}
