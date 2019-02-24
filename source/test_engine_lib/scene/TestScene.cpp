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
#include "TestScene.hpp"
#include "TestEngine.hpp"
#include "ModelImporter.hpp"

static Vector3 up_vector_point;
static Vector3 direction_vector_point;
static Vector3 plane_normal;

void TestScene::setup() {

    add_box({ 1.0f, 0, 0 });
    add_box({ 0, 1.2f, 0 });
    add_box({ 0, 0, 1.0f });

    camera->resolution = TestEngine::screen.size;
    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 0.5, 0, 1 });

    add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    cube_model = ModelImporter::import("textured_cube.blend", new Image(Paths::images_directory() + "cube_texture.png"));
    add_object(cube_model);
    cube_model->set_position({ 5, 5, 5 });
    cube_model->set_scale(0.1f);

    direction_vector = ModelImporter::import("Vector.blend");
    add_object(direction_vector);

    plane_normal_vector = ModelImporter::import("Vector.blend");
    add_object(plane_normal_vector);

    up_vector = ModelImporter::import("Vector.blend");
    add_object(up_vector);

    indicator = new scene::Box(0.05f);
    add_object(indicator);

}

void TestScene::each_frame() {
    draw_box(up_vector_point       );
    draw_box(direction_vector_point);
    draw_box(plane_normal          );

//    Endl;
//    Endl;
//    Endl;
//    Logvar(cube_model->view_matrix().to_string());

//    Vector3 ver = { 1, 1, 1 };
//    Logvar(ver.to_string());
//    ver = cube_model->view_matrix() * ver;
//    Logvar(ver.to_string());

//    draw_box(ver);
//    Endl;
//    Endl;
//    Endl;
//    Endl;
//    Endl;
    for (const auto& ver : cube_model->mesh()->vertices) {

//        Log(ver.to_string());
//        Endl;
//        Log((cube_model->view_matrix() * ver).to_string());

        draw_box(cube_model->view_matrix() * ver);
    }

}

void TestScene::set_vector(const Vector4& vec) {
    auto angle = vec.w;
    Logvar(angle);
    //angle -= math::half_pi<float>;
    Logvar(vec.to_string());

    //cube_model->look_at(vector.vector3());

    Matrix4 transform = Matrix4::transform::model_look_at(vec.vector3());

    cube_model->set_rotation_matrix(transform);

    up_vector_point        = {           0, 1,          0 };
    direction_vector_point = { -cos(angle), 0, sin(angle) };
    plane_normal           = direction_vector_point.cross(up_vector_point);

    up_vector_point        = transform * up_vector_point;
    direction_vector_point = transform * direction_vector_point;
    plane_normal           = transform * plane_normal;

    up_vector          ->look_at(up_vector_point       );
    direction_vector   ->look_at(direction_vector_point);
    plane_normal_vector->look_at(plane_normal          );

//        direction_vector   ->add_rotation(cube_model->rotation_matrix());
//        up_vector          ->add_rotation(cube_model->rotation_matrix());
//        plane_normal_vector->add_rotation(cube_model->rotation_matrix());

    indicator->set_position(vec.vector3());
}
