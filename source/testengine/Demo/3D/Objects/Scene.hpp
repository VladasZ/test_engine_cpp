//
//  Scene.hpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 9/17/18.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#pragma once

#include "Array.hpp"
#include "Camera.hpp"

class Object;

class Scene {

	Array<Object*> _objects;

public:

	Camera* camera = new Camera();

	virtual void setup();

	void addObject(Object* object);

	void draw();

};