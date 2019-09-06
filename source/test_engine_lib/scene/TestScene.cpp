//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "math.h"
#include "ui.hpp"

#include "Grid.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "Paths.hpp"
#include "Plane.hpp"
#include "TestView.hpp"
#include "Keyboard.hpp"
#include "GLWrapper.hpp"
#include "TestScene.hpp"
#include "VectorModel.hpp"
#include "GlobalEvents.hpp"
#include "ModelImporter.hpp"

using namespace gm;
using namespace te;

void TestScene::setup() {

    position_manipulator->is_hidden = false;

    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 1, 1, 1 });
    camera->flying_speed = 0.2f;

    add_object(monkey = ModelImporter::import("Monkey.blend"));
    monkey->set_position({ 2, 1, 1 });

//    cube = ModelImporter::import("textured_cube.blend",
//                                 new Image((Paths::images() / "cube_texture.png").string()));
//    
//    add_object(cube);
//    cube->set_scale(0.1f);

    add_object(walls.z = new scene::Plane(Size { 200, 200 }));
	walls.z->set_position({ 0, 0, -1.0f });

    add_object(walls.x = new scene::Plane(Size { 200, 200 }));
	walls.x->set_position({ -5.0f, 0, 0.0f });
	walls.x->look_at({ 1, 0, 0 });

    add_object(walls.y = new scene::Plane(Size { 200, 200 }));
	walls.y->set_position({ 0, -5.0f, 0.0f });
	walls.y->look_at({ 0, 1, 0 });

	walls.x->color = gm::Color::red;
	walls.y->color = gm::Color::green;
	walls.z->color = gm::Color::blue;

    add_object(new scene::VectorModel());

    light = new scene::PointLight({ 1, 1, 1 });
    light->velocity = { 0.011f, 0, 0.0f };

    add_light(light);
    
    auto test_view = new TestView();
    test_view->add_layout({ ui::Anchor::Background });
}

void TestScene::each_frame() {
    //monkey->draw_normals();
    draw_box(light->position());
    camera->set_position(camera->position() + gm::Vector3 { 0, 0, 0.001 });
}



