//
//  Object.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Object.hpp"
#include "Shader.hpp"
#include "Scene.hpp"
#include "Mesh.hpp"

Object::Object(Mesh* mesh) : _mesh(mesh) {

}

Object* Object::setScale(float scale) {
	_scale = scale;
	return this;
}

Object* Object::setPosition(const Point3& position) {
	_position = position;
	return this;
}

Point3 Object::position() const {
	return _position;
}

Object* Object::setRotation(const Point3& rotation) {
	_rotation = rotation;
	return this;
}

Point3 Object::rotation() const {
	return _rotation;
}

void Object::draw() {

	auto transformation = Matrix4::translation(_position);

	auto camera = _scene->camera->mvp();

	auto scale = Matrix4::scale(_scale);

	auto mvp = camera * transformation * scale;

	Shader::simple3D.use();
	Shader::simple3D.setMVPMatrix(mvp);
	Shader::simple3D.setUniformColor(C::green);

	_mesh->draw();
}
