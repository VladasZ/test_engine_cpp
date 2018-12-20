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
#include "Screen.hpp"
#include "GlobalEvents.hpp"

static float angle = 0;

Object::Object(Mesh* mesh) : _mesh(mesh) {
    
}

Object* Object::set_scale(float scale) {
	_scale = scale;
	return this;
}

Object* Object::set_position(const Vector3& position) {
	_position = position;
	return this;
}

Vector3 Object::position() const {
	return _position;
}

Object* Object::set_rotation(const Vector3& rotation) {
	_rotation = rotation;
	return this;
}

Vector3 Object::rotation() const {
	return _rotation;
}

void Object::draw() {
    
    static float rotationX = 0.f;
    static float rotationY = 0.f;
    static float fieldOfView = 200.0f;
    
    Events::touch.subscribe([&](ui::Point loc)
                            {
                                rotationX = loc.x / 100;
                                rotationY = loc.y / 100;
                            });
    
    static float nearPlane = 1.0f;
    static float farPlane = 5.0f;
    
    Matrix4 projection = Matrix4::perspective(fieldOfView, Screen::size.ratio(), nearPlane, farPlane);
    Matrix4 translation = Matrix4::translation({ 0, 0, -3.0f });
    Matrix4 _rotationY = Matrix4::rotation(rotationY, {0.0f, 1.0f, 0.0f});
    Matrix4 _rotationX = Matrix4::rotation(rotationX, {1.0f, 0.0f, 0.0f});

	Shader::colored3D.use();
    Shader::colored3D.set_mvp_matrix(_rotationY * _rotationX * translation * projection);
	Shader::colored3D.set_uniform_color(ui::C::green);

	_mesh->draw();
}
