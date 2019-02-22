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
#include "Paths.hpp"
#include "Image.hpp"
#include "TestScene.hpp"
#include "TestEngine.hpp"
#include "ModelImporter.hpp"


void TestScene::setup() {

    auto x_box = new scene::Box(0.1f); x_box->set_position({ 1.0f, 0, 0 }); add_object(x_box);
    auto y_box = new scene::Box(0.1f); y_box->set_position({ 0, 1.2f, 0 }); add_object(y_box);
    auto z_box = new scene::Box(0.1f); z_box->set_position({ 0, 0, 1.0f }); add_object(z_box);

    camera->resolution = TestEngine::screen.size;
    camera->set_target({ 0, 0, 0 });
    camera->set_position({ 0.5, 0, 1 });

    add_object(new scene::Grid({ 10, 10, }, { 10, 10 }));

    cube_model = ModelImporter::import("textured_cube.blend", new Image(Paths::images_directory() + "cube_texture.png"));
    add_object(cube_model);
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

void TestScene::set_vector(const Vector4& vec) {
    auto angle = vec.w;
    Logvar(angle);
    //angle -= math::half_pi<float>;
    Logvar(vec.to_string());

    //cube_model->look_at(vector.vector3());

    Matrix4 transform = Matrix4::transform::model_look_at(vec.vector3());

    cube_model->set_rotation_matrix(transform);

    Vector3 up_vector_point        {           0, 1,          0 };
    Vector3 direction_vector_point { -cos(angle), 0, sin(angle) };
    Vector3 plane_normal = direction_vector_point.cross(up_vector_point);

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
