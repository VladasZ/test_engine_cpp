//
//  PhysicsScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "Paths.hpp"
#include "Physics3D.hpp"
#include "PhysicsScene.hpp"
#include "GlobalEvents.hpp"
#include "ModelImporter.hpp"

using namespace te;
using namespace gm;
using namespace scene;


void PhysicsScene::_setup() {

    add_object(new Grid({ 200, 200 }, { 20, 20 }));
    add_object(ground = new BoxModel(100));
    camera->position = { 30, 10, 50 };

    ground->position = { 0, -80, 0 };

#ifdef USING_BULLET3D

    ground->add_rigid_body(100, 0, RigidBody::Shape::Box);

    auto box = ModelImporter::import("Sphere.blend");
    box->set_scale(10);
    box->position = { 0, 40, 0 };
    box->add_rigid_body(20, 1000, RigidBody::Shape::Sphere);
    add_object(box);

    static const int size = 2;

    for (int x = -size; x < size; x++) {
        for (int y = -size; y < size; y++) {
            for (int z = 0; z < size * 2; z++) {
               // auto object = ModelImporter::import("Sphere.blend");
                auto object = new BoxModel(2);
                object->position = {x * 2.0f, y * 2.0f, z * 2.0f };
                object->add_rigid_body(2, 1, RigidBody::Shape::Box);
                add_object(object);
            }
        }
    }

#endif

}
