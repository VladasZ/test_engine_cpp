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
    add_object(ball = ModelImporter::import("Sphere.blend"));

    camera->set_position({ 30, 10, 50 });

    ground->set_position({ 0, 0, -56 });
    ball->set_position({ 2, 2, 20 });

#ifdef USING_BULLET3D

    ground->rigidBody = new RigidBody(ground->position(), 100, 0, RigidBody::Shape::Box);
    ball->rigidBody = new RigidBody(ball->position(), 1, 1, RigidBody::Shape::Sphere);

    for (int x = -5; x < 5; x++) {
        for (int y = -5; y < 5; y++) {
            for (int z = 0; z < 10; z++) {
                auto ball = ModelImporter::import("Sphere.blend");
                ball->set_position({x * 2.0f, y * 2.0f, z * 2.0f });
                ball->rigidBody = new RigidBody(ball->position(), 2, 1, RigidBody::Shape::Sphere);
                add_object(ball);
            }
        }
    }

#endif

}
