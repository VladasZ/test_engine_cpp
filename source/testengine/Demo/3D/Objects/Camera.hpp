//
//  Camera.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Matrix4.hpp"

class Camera {
public:

	float _near = 1.0f;
	float _far = 5.0f;
	float _ratio;
	float _fov;

	Matrix4 _mvp;


	Camera();

	const Matrix4& mvp();

};
