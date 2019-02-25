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
#include "Paths.hpp"
#include "Image.hpp"
#include "Plane.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"
#include "ModelImporter.hpp"

void TestScene::setup() {

    add_box({ 1.0f, 0, 0 });
    add_box({ 0, 1.2f, 0 });
    add_box({ 0, 0, 1.0f });

    camera->resolution = TestEngine::screen.size;
    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 0.5, 0, 1 });
    camera->flying_speed = 0.2f;

    add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    cube_model = ModelImporter::import("textured_cube.blend", new Image(Paths::images_directory() + "cube_texture.png"));
    add_object(cube_model);
    //cube_model->set_position({ 5, 5, 5 });
    cube_model->set_scale(0.1f);

    line_vector = ModelImporter::import("Vector.blend");
    add_object(line_vector);
    line_vector->set_scale({ 1, 1, 10 });

    hor_plane_normal_vector = ModelImporter::import("Vector.blend");
    add_object(hor_plane_normal_vector);

    ver_plane_normal_vector = ModelImporter::import("Vector.blend");
    add_object(ver_plane_normal_vector);

    indicator = new scene::Box(0.05f);
    add_object(indicator);

    floor = new scene::Plane({ 20, 20 });
    //add_object(floor);

    hor_plane = new scene::Plane({ 1, 1 });
    add_object(hor_plane);

    ver_plane = new scene::Plane({ 1, 1 });
    add_object(ver_plane);
}

void TestScene::each_frame() {

    for (unsigned int i = 0; i < cube_model->mesh()->vertices.size(); i++) {
        const auto ver = cube_model->mesh()->vertices[i];
        const auto nor = cube_model->mesh()->normals[i];
        auto transformed_ver = (cube_model->view_matrix() * ver);
        auto transfotmed_nor = (cube_model->view_matrix().multiply_by_normal(nor));

        draw_box(transformed_ver, 0.01f);
        draw_box(transfotmed_nor + transformed_ver, 0.01f);
    }
 }



