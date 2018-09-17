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
	Point3 _position;
	Point3 _rotation;

public:

	Object(Mesh* mesh);

	Object* setScale(float scale);

	Object* setPosition(const Point3& position);
	Point3 position() const;

	Object* setRotation(const Point3& rotation);
	Point3 rotation() const;

	void draw();

};

