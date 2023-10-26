//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "PlaneModel.hpp"
#include "TestScene.hpp"
#include "VectorModel.hpp"
#include "GlobalEvents.hpp"

using namespace te;
using namespace gm;


void TestScene::setup() {

    position_manipulator->is_hidden = false;

    camera->set_target({ 0, 0, 0 });
    camera->edit_position() = {1, 1, 1 };
    camera->flying_speed = 0.2f;

    add_object(walls.z = new scene::PlaneModel(Size {200, 200 }));
    walls.z->edit_position() = {0, 0, -1.0f };

    add_object(walls.x = new scene::PlaneModel(Size {200, 200 }));
    walls.x->edit_position() = {-20.0f, 0, 0.0f };
	walls.x->look_at({ 1, 0, 0 });

    add_object(walls.y = new scene::PlaneModel(Size {200, 200 }));
    walls.y->edit_position() = {0, -20.0f, 0.0f };
	walls.y->look_at({ 0, 1, 0 });

	walls.x->color = gm::Color::red;
	walls.y->color = gm::Color::green;
	walls.z->color = gm::Color::blue;

    add_object(new scene::VectorModel());

    light = new scene::PointLight({ 1, 1, 1 });
    light->velocity = { 0.011f, 0, 0.0f };

    auto vector1 = new scene::VectorModel();

    add_object(vector1);

    add_object(marker_box = new scene::BoxModel({ 1, 1, 1 }));

    add_light(light);
}
