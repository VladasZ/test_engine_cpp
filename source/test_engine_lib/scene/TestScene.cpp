//
//  TestScene.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 2/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "math.h"

#include "Box.hpp"
#include "Grid.hpp"
#include "Mesh.hpp"
#include "Image.hpp"
#include "Paths.hpp"
#include "Plane.hpp"
#include "Vector.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"
#include "ModelImporter.hpp"

using namespace gm;

void TestScene::setup() {

    add_box({ 1.0f, 0, 0 });
    add_box({ 0, 1.2f, 0 });
    add_box({ 0, 0, 1.0f });

    camera->resolution = TestEngine::screen.size;
    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 1, 1, 1 });
    camera->flying_speed = 0.2f;

    add_object(monkey = ModelImporter::import("Monkey.blend"));
    monkey->set_position({ 2, 1, 1 });

    add_object(cube = ModelImporter::import("textured_cube.blend", new Image(Paths::images_directory() + "cube_texture.png")));
    cube->set_scale(0.1f);

    add_object(floor = new scene::Plane({ 200, 200 }));
    floor->set_position({ 0, 0, -1.0f });

    add_object(x_wall = new scene::Plane({ 200, 200 }));
    x_wall->set_position({ -5.0f, 0, 0.0f });
    x_wall->look_at({ 1, 0, 0 });

    add_object(y_wall = new scene::Plane({ 200, 200 }));
    y_wall->set_position({ 0, -5.0f, 0.0f });
    y_wall->look_at({ 0, 1, 0 });

    add_object(new scene::Vector());

    light = new scene::PointLight({ 1, 1, 1 });
    light->velocity = { 0.011f, 0, 0.0f };

    add_light(light);

}

void TestScene::each_frame() {
    cube ->draw_normals();
    floor->draw_normals();
    //monkey->draw_normals();
    draw_box(light->position());
}



