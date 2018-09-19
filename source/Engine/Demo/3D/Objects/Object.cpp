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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

using namespace glm;

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
    
    static float nearPlane = 1.0f;
    static float farPlane = 5.0f;
    
    rotationY = angle;
    
    mat4 projection = perspective(fieldOfView, Window::size.ratio(), nearPlane, farPlane);
    mat4 translationProjection = translate(projection, vec3(0, 0, -3.0f));
    mat4 fullTranslation = rotate(translationProjection, rotationX , vec3(1.0f, 0.0f, 0.0f));
    fullTranslation = rotate(fullTranslation, rotationY , vec3(1.0f, 0.0f, 0.0f));
    
    
//    auto transformation = Matrix4::translation(_position);
//
//    auto camera = _scene->camera->mvp();
//
//    auto scale = Matrix4::scale(_scale);
//
//    auto rotation = Matrix4::rotation(angle, { 0, 1, 0 });
//
//    auto mvp =
//    camera
//
//
//    //*
//   // transformation *
//   // scale
//    *
//    rotation
//    ;

	Shader::colored3D.use();
	Shader::colored3D.setMVPMatrix(fullTranslation);
	Shader::colored3D.setUniformColor(C::green);

	_mesh->draw();
}
