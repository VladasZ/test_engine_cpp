//
//  PhysicsScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "Grid.hpp"
#include "Paths.hpp"
#include "Physics3D.hpp"
#include "PhysicsScene.hpp"
#include "GlobalEvents.hpp"
#include "ModelImporter.hpp"

using namespace te;
using namespace gm;
using namespace scene;


void PhysicsScene::setup() {

    add_object(new Grid({ 200, 200 }, { 20, 20 }));
    add_object(ground = new BoxModel(100));
    camera->edit_position() = { 30, 10, 50 };

    ground->edit_position() = { 0, 0, -51 };

    ground->add_rigid_body(100, 0, RigidBody::Shape::Box);

    auto sphere = ModelImporter::import(Paths::models / "Sphere.blend");
    sphere->set_scale(10);
    sphere->edit_position() = { 0, 0, 100 };
    sphere->add_rigid_body(20, 20, RigidBody::Shape::Box);
    add_object(sphere);

    const int size = 3;

    //for (int x = -size; x < size; x++) {
    //    for (int y = -size; y < size; y++) {
    //        for (int z = 0; z < size * 2; z++) {
    //            auto object = new BoxModel(2);
    //            object->edit_position() = { x * 2.0f, y * 2.0f, z * 2.0f + 10 };
    //            object->color = Color::random();
    //            object->add_rigid_body(2, 1, RigidBody::Shape::Box);
    //            add_object(object);
    //        }
    //    }
    //}

    Events::frame_drawn = [=] {
       // Log << sphere->position();
       // Log << sphere->rigid_body()->position();
    };

}
