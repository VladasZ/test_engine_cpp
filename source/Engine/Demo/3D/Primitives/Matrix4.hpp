//
//  Matrix4.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/13/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Point3.hpp"
#include "String.hpp"

class Matrix4 {
    
public:
    
    static const size_t size = 16;
    
    float data[4][4];
    
    Matrix4();
	Matrix4(float value);
    Matrix4(const std::initializer_list<float>& list);
    
    template <class CompatibleClass>
    Matrix4(const CompatibleClass& obj) {
        static_assert(sizeof(Matrix4) == sizeof(CompatibleClass), "Matrix4 invalid initializer");
        memcpy(&data[0][0], (void *)&obj, sizeof(Matrix4));
    }
    
    Matrix4 operator *(const Matrix4& mat) const;
    Matrix4& operator *=(const Matrix4& mat);

	String toString() const;

	static String bufferToString(const float* buffer);

	static Matrix4 scale(float scale);
	static Matrix4 translation(const Point3& location);
    static Matrix4 rotation(float angle, const Point3& axis);
	static Matrix4 perspective(float fovy, float aspect, float zNear, float zFar);

};
