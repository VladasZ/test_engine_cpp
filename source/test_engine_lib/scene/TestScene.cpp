//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "math.h"

#include           "Box.hpp"
#include          "Grid.hpp"
#include          "Mesh.hpp"
#include         "Image.hpp"
#include         "Paths.hpp"
#include         "Plane.hpp"
#include        "Vector.hpp"
#include     "TestScene.hpp"
#include    "TestEngine.hpp"
#include "ModelImporter.hpp"

void TestScene::setup() {

    add_box({ 1.0f, 0, 0 });
    add_box({ 0, 1.2f, 0 });
    add_box({ 0, 0, 1.0f });

    camera->resolution = TestEngine::screen.size;
    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 1, 1, 1 });
    camera->flying_speed = 0.2f;

    add_object(cube = ModelImporter::import("textured_cube.blend", new Image(Paths::images_directory() + "cube_texture.png")));
    cube->set_scale(0.1f);

    add_object(floor = new scene::Plane({ 20, 20 }));
    floor->set_position({ 0, 0, -1.0f });

    add_object(wall = new scene::Plane({ 20, 20 }));
    wall->set_position({ -1.0f, 0, 0.0f });
    wall->look_at({ 1, 0, 0 });

    add_object(new scene::Vector());

    light = new scene::PointLight({ 1, 1, 1 });
    light->velocity = { 0.0f, 0, -0.01f };

    add_light(light);

}

void TestScene::each_frame() {
    cube ->draw_normals();
    floor->draw_normals();
    draw_box(light->position());
}



