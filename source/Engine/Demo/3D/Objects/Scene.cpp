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
#include "FileManager.hpp"

void Scene::setup() {

	auto object = new Object(DoTheImportThing(FileManager::assetsDirectory() + "/Models/Box.blend"));

	addObject(object);

	settingsView->onX.subscribe([=](float x) {
		auto pos = object->position();
		pos.x = x;
		object->setPosition(pos);
	});

	settingsView->onY.subscribe([=](float y) {
		auto pos = object->position();
		pos.y = y;
		object->setPosition(pos);
	});

	settingsView->onZ.subscribe([=](float z) {
		auto pos = object->position();
		pos.z = z * 20;
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
