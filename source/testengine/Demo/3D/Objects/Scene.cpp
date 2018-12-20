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
#include "Assimp.hpp"
#include "Paths.hpp"

void Scene::setup() {

	auto object = new Object(import_model(Paths::assets_directory() + "/Models/Monkey.blend"));

	addObject(object);

}

void Scene::addObject(Object* object) {
	object->_scene = this;
	_objects.push_back(object);
}

void Scene::draw() {
	for (auto object : _objects)
		object->draw();
}
