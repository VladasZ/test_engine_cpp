//
//  Matrix4.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point3.hpp"

class Matrix4 {
    
public:
    
    static const size_t size = 16;
    
    float data[4][4];
    
    Matrix4();
	Matrix4(float value);
    Matrix4(const std::initializer_list<float>& list);
    
	Matrix4 operator *(const Matrix4& mat) const;

	static Matrix4 perspective(float fovy, float aspect, float zNear, float zFar);

};