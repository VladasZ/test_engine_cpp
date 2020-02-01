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
    add_object(box = new BoxModel(2));

    auto sphere = ModelImporter::import("textured_cube.blend",
                                 new Image((Paths::images() / "cube_texture.png")));

    add_object(sphere);

    ground->set_position({ 0, -56, 0 });
    box->set_position({ 2, 10, 0 });

    Physics3D::init();

    Events::frame_drawn.subscribe([&] {
        Physics3D::update();
        ground->set_position(Physics3D::ground_position);
        box->set_position(Physics3D::box_position);
    });

}
