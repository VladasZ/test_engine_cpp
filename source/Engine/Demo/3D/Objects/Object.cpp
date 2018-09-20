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
#include "RootView.hpp"
#include "Window.hpp"
#include "GlobalEvents.hpp"

static float angle = 0;

Object::Object(Mesh* mesh) : _mesh(mesh) {

    settingsView->onX.subscribe([&](float angl){ angle = -10 + angl * 20; });
    
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
    
    static float rotationX = 0.f;
    static float rotationY = 0.f;
    static float fieldOfView = 200.0f;
    
    Events::touch.subscribe([&](Point loc)
                            {
                                rotationX = loc.x / 100;
                                rotationY = loc.y / 100;
                            });
    
    static float nearPlane = 1.0f;
    static float farPlane = 5.0f;
    
    Matrix4 projection = Matrix4::perspective(fieldOfView, Window::size.ratio(), nearPlane, farPlane);
    Matrix4 translation = Matrix4::translation({ 0, 0, -3.0f });
    Matrix4 _rotationY = Matrix4::rotation(rotationY, {0.0f, 1.0f, 0.0f});
    Matrix4 _rotationX = Matrix4::rotation(rotationX, {1.0f, 0.0f, 0.0f});

	Shader::colored3D.use();
    Shader::colored3D.setMVPMatrix(_rotationY * _rotationX * translation * projection);
	Shader::colored3D.setUniformColor(C::green);

	_mesh->draw();
}
