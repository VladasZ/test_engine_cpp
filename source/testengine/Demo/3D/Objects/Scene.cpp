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
#include "Assimp.hpp"
#include "Paths.hpp"

void Scene::setup() {

	auto object = new Object(import_model(Paths::assets_directory() + "/Models/Monkey.blend"));

	addObject(object);

	settingsView->onX.subscribe([=](float x) {
		auto pos = object->position();
		pos.x = x;
		object->set_position(pos);
	});

	settingsView->onY.subscribe([=](float y) {
		auto pos = object->position();
		pos.y = y;
		object->set_position(pos);
	});

	settingsView->onZ.subscribe([=](float z) {
		auto pos = object->position();
		pos.z = z * 20;
		object->set_position(pos);
	});

	settingsView->onScale.subscribe([=](float scale) {
		object->set_scale(scale);
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
