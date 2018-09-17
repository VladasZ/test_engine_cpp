//
//  Scene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#include "Scene.hpp"
#include "Object.hpp"
#include "Box.hpp"
#include "RootView.hpp"

void Scene::setup() {

	auto object = new Object(new Box());

	addObject(object);

	settingsView->onX.subscribe([=](float x) {
		auto pos = object->position();
		pos.x = x * 100;
		object->setPosition(pos);
	});

	settingsView->onY.subscribe([=](float y) {
		auto pos = object->position();
		pos.y = y * 100;
		object->setPosition(pos);
	});

	settingsView->onZ.subscribe([=](float z) {
		auto pos = object->position();
		pos.z = z * 100;
		object->setPosition(pos);
	});

	settingsView->onScale.subscribe([=](float scale) {
		object->setScale(scale);
	});

}

void Scene::addObject(Object* object) {
	object->_scene = this;
	_objects.push_back(object);
}

void Scene::draw() {
	for (auto object : _objects)
		object->draw();
}
