//
//  Object.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Matrix4.hpp"

class Mesh;
class Scene;

class Object {

	friend Scene;

	Mesh* _mesh;
	Scene* _scene;
	Matrix4 _mvp;

	float _scale = 1;
	Vector3 _position;
	Vector3 _rotation;

public:

	Object(Mesh* mesh);

	Object* set_scale(float scale);

	Object* set_position(const Vector3& position);
	Vector3 position() const;

	Object* set_rotation(const Vector3& rotation);
	Vector3 rotation() const;

	void draw();

};

