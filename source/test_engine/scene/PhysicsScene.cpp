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
    camera->set_position({ 30, 10, 50 });

    ground->set_position({ 0, 0, -52 });

#ifdef USING_BULLET3D

    ground->add_rigid_body(100, 0, RigidBody::Shape::Box);

    static const int size = 5;

    for (int x = -size; x < size; x++) {
        for (int y = -size; y < size; y++) {
            for (int z = 0; z < size * 2; z++) {
                auto ball = ModelImporter::import("Sphere.blend");
                ball->set_position({x * 2.0f, y * 2.0f, z * 2.0f });
                ball->add_rigid_body(2, 1, RigidBody::Shape::Sphere);
                add_object(ball);
            }
        }
    }

#endif

}
